// DataAdmin.cpp: implementation of the CDataAdmin class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DataAdmin.h"

#include "Winuser.h"
#include "../include_auto/globalAuto.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDataAdmin::CDataAdmin()
{	
}

CDataAdmin::~CDataAdmin()
{

	DeleteAll();
}

// 2009.11.11 -hidden-
void CDataAdmin::DeleteAll()
{
	int nCondSize = 0;
	int nSize = m_arrGroups.GetSize();
	
	for(int i = 0; i < nSize; ++i)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);
		for(int j = 0; j < nCondSize; ++j)
		{
			pGroup->arrConGrpInfo.RemoveAll();
			delete pGroup;
		}
	}
	
	m_arrGroups.RemoveAll();
}

// 2009.11.13 -hidden-
void CDataAdmin::MakeGroupStruct(int nIndex, int nGroup)
{
	if(nIndex < 0)
		return;

	int nGroups = m_arrGroups.GetSize();
	GROUP_INFO* pGroupInfo = NULL;
	
	for(int i = 0; i < nGroups; ++i)
	{
		pGroupInfo = m_arrGroups.GetAt(i);
		if(pGroupInfo->nGroup == nGroup)
			return;
	}
	
	pGroupInfo = new GROUP_INFO;
	pGroupInfo->nGroup = nGroup;
	
	if(!m_arrGroups.GetSize())
	{
		m_arrGroups.Add(pGroupInfo);
		return;
	}

	if(nGroup == 0)
		m_arrGroups.InsertAt(0, pGroupInfo);
	else if(1 == nIndex)
	{
		if(!m_arrGroups.GetSize())
			m_arrGroups.Add(pGroupInfo);
		else
		{
			if(0 == m_arrGroups.GetAt(0)->nGroup)
				m_arrGroups.InsertAt(nIndex, pGroupInfo);
			else
				m_arrGroups.InsertAt(nIndex - 1, pGroupInfo);
		}
	}
	else
		m_arrGroups.InsertAt(nIndex, pGroupInfo);
}


BOOL CDataAdmin::GetMoveFieldIDToInfo(CString strHeadID, HeadMoveInfo  &stHeadMoveInfo)
{
	BOOL bResult = TRUE;
	BOOL bHaveFieldID = FALSE;
	HeadInfoType      stHeadType;
	
	MSXML2::IXMLDOMNodePtr		      pNIndex;		//# Header
	MSXML2::IXMLDOMNodeListPtr	    pNS_FItem;	//# Item List
	MSXML2::IXMLDOMNodePtr			    pN_FItem;   //# Item
	MSXML2::IXMLDOMNamedNodeMapPtr	pNA_FItem;
	
	if( m_bMoveSysLoadedXMLFile == VARIANT_FALSE || 
		m_bFixSysLoadedXMLFile == VARIANT_FALSE ) 
	{
		bResult = FALSE;
		return bResult;
	}
	
	int nColCount = 0;
	int nFindPos = 0;
	CString tmpStr = strHeadID;
	CString ExtractStr;
	
	if (!tmpStr.IsEmpty()) 
	{
		while (nFindPos >= 0) 
		{
			nFindPos = tmpStr.Find("/");
			if (nFindPos < 0)
				break;
			ExtractStr = tmpStr.Mid(0, nFindPos);
			tmpStr = tmpStr.Mid(nFindPos + 1, tmpStr.GetLength());
			
			try {
				if (ExtractStr.Left(1).Compare("5") == 0) 
					pNIndex = m_pMoveSysDOM->selectSingleNode("INDEX");
				else if (ExtractStr.Left(1).Compare("9")== 0) 
					pNIndex = m_pFixSysDOM->selectSingleNode("INDEX");
				
				pNS_FItem  = pNIndex->selectNodes("FITEM");
				
				int nCount, nLength;
				CString strTemp;
				nLength = pNS_FItem->length;
				for (nCount = 0; nCount < nLength; nCount++)
				{
					pN_FItem = pNS_FItem->item[nCount];	
					
					MSXML2::IXMLDOMNodePtr	pNAttributeTemp;
					pNA_FItem= pN_FItem->attributes;
					
					pNAttributeTemp = pNA_FItem->getNamedItem("ID");
					strTemp = CString((PCHAR)pNAttributeTemp->text);
					
					if (strTemp.Compare(ExtractStr) == 0)
					{
						pNAttributeTemp = pNA_FItem->getNamedItem("ID");
						strTemp = CString((PCHAR)pNAttributeTemp->text);
						stHeadType.lHeadID = atol(strTemp);
						
						pNAttributeTemp = pNA_FItem->getNamedItem("FIELD_NAME");
						stHeadType.strHeadName = CString((PCHAR)pNAttributeTemp->text);
						
						pNAttributeTemp = pNA_FItem->getNamedItem("UNIT_NUM");
						strTemp = CString((PCHAR)pNAttributeTemp->text);
						stHeadType.nUnitNum = atoi(strTemp);
						
						pNAttributeTemp = pNA_FItem->getNamedItem("UNIT_TEXT");
						stHeadType.strUnitText = CString((PCHAR)pNAttributeTemp->text);
						
						pNAttributeTemp = pNA_FItem->getNamedItem("DATA_TYPE");
						stHeadType.strDataType = CString((PCHAR)pNAttributeTemp->text);
						
						pNAttributeTemp = pNA_FItem->getNamedItem("DATA_LENGTH");
						strTemp = CString((PCHAR)pNAttributeTemp->text); 
						stHeadType.nDataLength = atoi(strTemp);
						
						pNAttributeTemp = pNA_FItem->getNamedItem("COL_WIDTH");
						strTemp = CString((PCHAR)pNAttributeTemp->text);
						stHeadType.nColWidth = atoi(strTemp);
						
						pNAttributeTemp = pNA_FItem->getNamedItem("ALIGN");
						stHeadType.strAlignment = CString((PCHAR)pNAttributeTemp->text);
						
						stHeadMoveInfo.stHeadType[nColCount] = stHeadType;
						
						bHaveFieldID = TRUE;
						break;
					}
				}
			}
			catch (_com_error e)
			{
				bResult = FALSE;
				return bResult;
			}
			
			
			nColCount++;
			bHaveFieldID = FALSE;
		}
	}
	
	stHeadMoveInfo.nColCnt = nColCount;
	
	return bResult;
}


BOOL CDataAdmin::GetMoveSysFieldIDToInfo(CString ExtractStr, HeadInfoType &stHeadType)
{
	BOOL bHaveFieldID = FALSE;
	
	MSXML2::IXMLDOMNodePtr		      pNIndex;		//# Header
	MSXML2::IXMLDOMNodeListPtr	    pNS_FItem;		//# Item List
	MSXML2::IXMLDOMNodePtr			    pN_FItem;   //# Item
	MSXML2::IXMLDOMNamedNodeMapPtr	pNA_FItem;
	
	try {
		pNIndex = m_pMoveSysDOM->selectSingleNode("INDEX");
		
		pNS_FItem  = pNIndex->selectNodes("FITEM");
		
		int nCount, nLength;
		CString strTemp;
		nLength = pNS_FItem->length;
		for(nCount = 0; nCount < nLength; nCount++)
		{
			pN_FItem = pNS_FItem->item[nCount];	
			
			MSXML2::IXMLDOMNodePtr	pNAttributeTemp;
			pNA_FItem= pN_FItem->attributes;
			
			pNAttributeTemp = pNA_FItem->getNamedItem("ID");
			strTemp = CString((PCHAR)pNAttributeTemp->text);
			
			if (strTemp.Compare(ExtractStr) == 0)
			{
				pNAttributeTemp = pNA_FItem->getNamedItem("ID");
				strTemp = CString((PCHAR)pNAttributeTemp->text);
				stHeadType.lHeadID = atol(strTemp);
				
				pNAttributeTemp = pNA_FItem->getNamedItem("FIELD_NAME");
				stHeadType.strHeadName = CString((PCHAR)pNAttributeTemp->text);
				
				pNAttributeTemp = pNA_FItem->getNamedItem("UNIT_NUM");
				strTemp = CString((PCHAR)pNAttributeTemp->text);
				stHeadType.nUnitNum = atoi(strTemp);
				
				pNAttributeTemp = pNA_FItem->getNamedItem("UNIT_TEXT");
				stHeadType.strUnitText = CString((PCHAR)pNAttributeTemp->text);
				
				pNAttributeTemp = pNA_FItem->getNamedItem("DATA_TYPE");
				stHeadType.strDataType = CString((PCHAR)pNAttributeTemp->text);
				
				pNAttributeTemp = pNA_FItem->getNamedItem("DATA_LENGTH");
				strTemp = CString((PCHAR)pNAttributeTemp->text); 
				stHeadType.nDataLength = atoi(strTemp);
				
				pNAttributeTemp = pNA_FItem->getNamedItem("COL_WIDTH");
				strTemp = CString((PCHAR)pNAttributeTemp->text);
				stHeadType.nColWidth = atoi(strTemp);
				
				pNAttributeTemp = pNA_FItem->getNamedItem("ALIGN");
				stHeadType.strAlignment = CString((PCHAR)pNAttributeTemp->text);
				
				bHaveFieldID = TRUE;
				break;
			}
		}
	}
	catch (_com_error e)
	{
		bHaveFieldID = FALSE;
	}
	
	return bHaveFieldID;
}


BOOL CDataAdmin::AddCondition(int nGroup, int nElementIndex, OneConditionInfo  stOneConditionInfo, CString strFieldID,
								BOOL bResultViewDefVal, BOOL bLoadFlag)
{
	strFieldID.TrimRight(" ");
	strFieldID.TrimLeft(" ");

	ConditionGroupInfo  stConditionGroupInfo;
	
	stConditionGroupInfo.nGroup = nGroup;
	
	stConditionGroupInfo.strElement = CONDITION_INDEX[nElementIndex];
	
	stConditionGroupInfo.stOneConditionInfo = stOneConditionInfo;
	
	// 20120723 ssj - 서버자동주문 >>
	//stConditionGroupInfo.stOneConditionInfo.stCondition.GroupNo = nGroup;
	SetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giGroupNo, sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giGroupNo), nGroup);
	// 20120723 ssj - 서버자동주문 <<

	if (strFieldID.IsEmpty() == FALSE)
	{
		//# 값보기 정보 
		if (GetMoveFieldIDToInfo(strFieldID, stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo) == FALSE)
			return FALSE;
		else
		{
			if (bLoadFlag == FALSE)
			{
				int nValViewCnt = stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.nColCnt;
				
				// 20120723 ssj - 서버자동주문 >>
				//stConditionGroupInfo.stOneConditionInfo.stCondition.ResultViewNum = nValViewCnt;
				SetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giResultViewNum, sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giResultViewNum), nValViewCnt);
				// 20120723 ssj - 서버자동주문 <<

				stConditionGroupInfo.stOneConditionInfo.bFieldState = (nValViewCnt > 0) ? TRUE : FALSE;    
				stConditionGroupInfo.stOneConditionInfo.bFieldEnable = !stConditionGroupInfo.stOneConditionInfo.bFalg;
			}
		}
	}
	else
	{
		stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.nColCnt = 0;
		stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.bView = FALSE;
		

		SetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giResultViewNum, sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giResultViewNum), 0);
		
		stConditionGroupInfo.stOneConditionInfo.bFieldState = FALSE;    
		stConditionGroupInfo.stOneConditionInfo.bFieldEnable = FALSE;
	}
	stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.strElement = CONDITION_INDEX[nElementIndex];
	
	//# 값보기
	stConditionGroupInfo.stOneConditionInfo.bFieldVal = bResultViewDefVal;          
	stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.bView = bResultViewDefVal;



	int nGroups = m_arrGroups.GetSize();
	GROUP_INFO* pGroupInfo = NULL;

	for(int i = 0; i < nGroups; ++i)
	{
		pGroupInfo = m_arrGroups.GetAt(i);
		if(pGroupInfo->nGroup == nGroup)
		{
			pGroupInfo->arrConGrpInfo.Add(stConditionGroupInfo);
			return TRUE;
		}
	}

	pGroupInfo = new GROUP_INFO;
	pGroupInfo->nGroup = nGroup;
	pGroupInfo->arrConGrpInfo.Add(stConditionGroupInfo);

	if(nGroup == 0)
		m_arrGroups.InsertAt(0, pGroupInfo);
	else
		m_arrGroups.Add(pGroupInfo);
	
#ifdef _DEBUG
	DebugInputDataView();
#endif
	
	return TRUE;
}


BOOL CDataAdmin::InsertCondition(int nGroup, CString strElement, int nElementIndex,	OneConditionInfo  stOneConditionInfo, 
								 CString strFieldID, BOOL	bResultViewDefVal, 	BOOL bLoadFlag)
{
	strFieldID.TrimRight(" ");
	strFieldID.TrimLeft(" ");

	ConditionGroupInfo  stConditionGroupInfo;
	
	stConditionGroupInfo.nGroup = nGroup;
	stConditionGroupInfo.strElement = CONDITION_INDEX[nElementIndex];
	stConditionGroupInfo.stOneConditionInfo = stOneConditionInfo;
	
	SetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giGroupNo, sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giGroupNo), nGroup);

	if (strFieldID.IsEmpty() == FALSE)
	{
		//# 값보기 정보 
		if (GetMoveFieldIDToInfo(strFieldID, stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo) == FALSE)
			return FALSE;
		else
		{
			if (bLoadFlag == FALSE)
			{
				int nValViewCnt = stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.nColCnt;
				// 20120723 ssj - 서버자동주문 >>
				//stConditionGroupInfo.stOneConditionInfo.stCondition.ResultViewNum = nValViewCnt;
				SetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giResultViewNum,
						sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giResultViewNum), nValViewCnt);
				// 20120723 ssj - 서버자동주문 <<

				stConditionGroupInfo.stOneConditionInfo.bFieldState = (nValViewCnt > 0) ? TRUE : FALSE;    
				stConditionGroupInfo.stOneConditionInfo.bFieldEnable = !stConditionGroupInfo.stOneConditionInfo.bFalg;
			}
		}
	}
	else
	{
		stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.nColCnt = 0;
		stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.bView = FALSE;
		
		SetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giResultViewNum,
				sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giResultViewNum), 0);
					
		stConditionGroupInfo.stOneConditionInfo.bFieldState = FALSE;    
		stConditionGroupInfo.stOneConditionInfo.bFieldEnable = FALSE;
	}
	stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.strElement = CONDITION_INDEX[nElementIndex];
	
	//# 값보기
	stConditionGroupInfo.stOneConditionInfo.bFieldVal = bResultViewDefVal;          
	stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.bView = bResultViewDefVal;



#ifdef _DEBUG
	DebugInputDataView();
#endif
	
	return TRUE;
}


BOOL CDataAdmin::ModifyCondition(CString strElement, OneConditionInfo  stOneConditionInfo, CString strFieldID, 
								 BOOL	bResultViewDefVal,/* = FALSE*/ BOOL	bLoadFlag /*= FALSE*/)
{
	
// 2009.11.11 -hidden- -------------------------------------------------
	strFieldID.TrimRight(" ");
	strFieldID.TrimLeft(" ");
	
	ConditionGroupInfo  stConditionGroupInfo;
	GetElementToGroup(strElement, stConditionGroupInfo);
	stConditionGroupInfo.stOneConditionInfo = stOneConditionInfo;

	if (strFieldID.IsEmpty() == FALSE)
	{
		//# 값보기 정보 
		if (GetMoveFieldIDToInfo(strFieldID, stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo) == FALSE)
			return FALSE;
		else
		{
			if (bLoadFlag == FALSE)
			{
				int nValViewCnt = stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.nColCnt;
				SetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giResultViewNum,
						sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giResultViewNum), nValViewCnt);

				
				stConditionGroupInfo.stOneConditionInfo.bFieldState = (nValViewCnt > 0) ? TRUE : FALSE;    
				stConditionGroupInfo.stOneConditionInfo.bFieldEnable = !stConditionGroupInfo.stOneConditionInfo.bFalg;
			}
		}
	}
	else
	{
		stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.nColCnt = 0;
		stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.bView = FALSE;
		
		SetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giResultViewNum,
				sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giResultViewNum), 0);
		
		stConditionGroupInfo.stOneConditionInfo.bFieldState = FALSE;    
		stConditionGroupInfo.stOneConditionInfo.bFieldEnable = FALSE;
	}
	stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.strElement = strElement;
	
	//# 값보기
	stConditionGroupInfo.stOneConditionInfo.bFieldVal = bResultViewDefVal;          
	stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.bView = bResultViewDefVal;

	return TRUE;
}


int CDataAdmin::SetElementStandLine()
{

	int nResult = 0;
	int nElementIndex = 0;
	
	ConditionGroupInfo	stConditionGroupInfo;
	int nCodeSize = 0;

	int nSize = m_arrGroups.GetSize();
	for (int nGroupIndex = 0; nGroupIndex < nSize; nGroupIndex++)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(nGroupIndex);
		nCodeSize = pGroup->arrConGrpInfo.GetSize();

		for (int nIndex = 0; nIndex < nCodeSize; nIndex++)
		{
			stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(nIndex);
			stConditionGroupInfo.strElement = CONDITION_INDEX[nElementIndex];
			pGroup->arrConGrpInfo.SetAt(nIndex, stConditionGroupInfo);
			nElementIndex++;
			nResult++;
		}
	}

	return nResult;
}


BOOL CDataAdmin::SetDataGroupSort()
{  
	BOOL bResult = FALSE;

	bResult = TRUE;

	return bResult;
}


BOOL CDataAdmin::ModifyOneCondition(CString strElement, OneConditionInfo stConditionInfo)
{

	ConditionGroupInfo  stConditionGroupInfo;
	
	strElement.TrimLeft();
	strElement.TrimRight();
	
	int nSize = m_arrGroups.GetSize();
	for(int i = 0; i < nSize; ++i)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);
		int nItems = pGroup->arrConGrpInfo.GetSize();
		for(int j = 0; j < nItems; ++j)
		{
			stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);
			
			stConditionGroupInfo.strElement.TrimLeft();
			stConditionGroupInfo.strElement.TrimRight();
			if (stConditionGroupInfo.strElement.Compare(strElement) == 0)
			{
				stConditionGroupInfo.stOneConditionInfo = stConditionInfo;
				pGroup->arrConGrpInfo.SetAt(j, stConditionGroupInfo);
				return TRUE; 
			}
		}
	}

	return FALSE;
}


BOOL CDataAdmin::ModifyConditionLogicOpt(CStringArray *psaLogicInfoData)
{

	BOOL bResult = FALSE;
	ConditionGroupInfo  stConditionGroupInfo;
	
	CString strElement = psaLogicInfoData->GetAt(0);
	CString strOpt = psaLogicInfoData->GetAt(1);
	int nCondSize = 0;

	int nSize = m_arrGroups.GetSize();
	for (int nIndex = 0; nIndex < nSize; nIndex++)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(nIndex);
		nCondSize = pGroup->arrConGrpInfo.GetSize();

		for(int j = 0; j < nCondSize; ++j)
		{
			stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);
			if (stConditionGroupInfo.strElement == strElement)
			{
				stConditionGroupInfo.stOneConditionInfo.stCondition.Operator = (strOpt == "0")?'0':'1';
				pGroup->arrConGrpInfo.SetAt(j, stConditionGroupInfo);
				
				bResult = TRUE;
			}
		}
	}

	return bResult;
}

BOOL CDataAdmin::ModifyConditionTargetBase(int nGroup, int nTargetIndex, int nOutType/*= -1*/)
{

	BOOL bResult = FALSE;
	ConditionGroupInfo  stConditionGroupInfo;
	int nCondSize = 0;

	int nSize = m_arrGroups.GetSize();
	for (int nIndex = 0; nIndex < nSize; nIndex++)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(nIndex);
		nCondSize = pGroup->arrConGrpInfo.GetSize();

		if (nGroup == pGroup->nGroup)
		{
			for(int j = 0; j < nCondSize; ++j)
			{
				stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);
				
				BOOL bChangeState = TRUE;
				
				int nSetTargetIndex = 0;
				if (stConditionGroupInfo.stOneConditionInfo.nTargetBaseType == 0)
				{
					nSetTargetIndex = TARGETINDEX_TYPE1[nTargetIndex];

					if (nOutType == 1)		//# 일간제외 => 2004.09.21
						bChangeState = FALSE;
				}
				else if (stConditionGroupInfo.stOneConditionInfo.nTargetBaseType == 1)  //# 일간 고정
					bChangeState = FALSE;
				else if (stConditionGroupInfo.stOneConditionInfo.nTargetBaseType == 2)  //# 분 고정
				{
					if ((TARGETINDEX_TYPE3[0] <= nTargetIndex) &&
						  (TARGETINDEX_TYPE3[_countof(TARGETINDEX_TYPE3) - 1] >= nTargetIndex))
					{
						int nIndex = 0;
						for (nIndex = 0; nIndex < _countof(TARGETINDEX_TYPE3); nIndex++)
						{
							if (TARGETINDEX_TYPE3[nIndex] == nTargetIndex)
								break;
						}
						nSetTargetIndex = TARGETINDEX_TYPE3[nIndex];
					}
					else
						bChangeState = FALSE;
				}

				if (bChangeState == TRUE)
				{
					SetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giTargetBase,
							sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giTargetBase), nSetTargetIndex);

					pGroup->arrConGrpInfo.SetAt(j, stConditionGroupInfo);
				}
				
				bResult = TRUE;
			}
		}
	}

	return bResult;
}

BOOL CDataAdmin::ModifyConditionTerm(int nGroup, int nTerm, CString strCase)
{
	BOOL bResult = FALSE;
	ConditionGroupInfo  stConditionGroupInfo;
	int nCondSize = 0;

	int nSize = m_arrGroups.GetSize();
	for (int nIndex = 0; nIndex < nSize; nIndex++)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(nIndex);
		nCondSize = pGroup->arrConGrpInfo.GetSize();

		if (nGroup == pGroup->nGroup)
		{
			for(int j = 0; j < nCondSize; ++j)
			{
				stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);
			
				if (strCase == "START")
					SetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giSTerm, sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giSTerm), nTerm);
				else if (strCase == "END")
					SetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giETerm, sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giETerm), nTerm);

				pGroup->arrConGrpInfo.SetAt(j, stConditionGroupInfo);
				bResult = TRUE;
			}
		}
	}
	return bResult;
}


BOOL CDataAdmin::ModifyConditionTerm(int nGroup, int nSTerm, int nETerm)
{
	BOOL bResult = FALSE;
	ConditionGroupInfo  stConditionGroupInfo;
	int nCondSize = 0;

	int nSize = m_arrGroups.GetSize();
	for (int nIndex = 0; nIndex < nSize; nIndex++)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(nIndex);
		nCondSize = pGroup->arrConGrpInfo.GetSize();
	
		if(pGroup->nGroup == nGroup)
		{
			for(int j = 0; j < nCondSize; ++j)
			{
				stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);

				SetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giSTerm, sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giSTerm), nSTerm);
				SetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giETerm, sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giETerm), nETerm);

				pGroup->arrConGrpInfo.SetAt(j, stConditionGroupInfo);
				bResult = TRUE;
			}
		}
	}

	return bResult;
}

BOOL CDataAdmin::ModifyOneConditionTargetBase(CString strElement, int nTargetIndex)
{
	BOOL bResult = FALSE;
	ConditionGroupInfo  stConditionGroupInfo;
	int nCondSize = 0;

	int nSize = m_arrGroups.GetSize();
	for (int nIndex = 0; nIndex < nSize; nIndex++)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(nIndex);
		nCondSize = pGroup->arrConGrpInfo.GetSize();

		for(int j = 0; j < nCondSize; ++j)
		{
			stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);
			
			if (strElement == stConditionGroupInfo.strElement)
			{
				SetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giTargetBase, 
						sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giTargetBase), nTargetIndex);
				pGroup->arrConGrpInfo.SetAt(j, stConditionGroupInfo);
				
				bResult = TRUE;
			}
		}
	}

	return bResult;
}


BOOL CDataAdmin::ModifyConditionCheck(CString strElement, BOOL bView)
{

	BOOL bResult = FALSE;
	ConditionGroupInfo  stConditionGroupInfo;
    
	if (GetElementToGroup(strElement, stConditionGroupInfo))
	{
		stConditionGroupInfo.stOneConditionInfo.bFalg = bView;
		
		if (bView == TRUE)
		{
			if (stConditionGroupInfo.stOneConditionInfo.bFieldState == TRUE)
			{
				if (stConditionGroupInfo.stOneConditionInfo.stCondition.Reverse == '0')
					stConditionGroupInfo.stOneConditionInfo.bFieldEnable = FALSE;
			}
		}
		else
		{
			if (stConditionGroupInfo.stOneConditionInfo.bFieldState == TRUE)
			{
				stConditionGroupInfo.stOneConditionInfo.bFieldEnable = TRUE;
				stConditionGroupInfo.stOneConditionInfo.bFieldVal = FALSE;
			}
		}
		bResult = ModifyOneCondition(strElement, stConditionGroupInfo.stOneConditionInfo);
	}

	return bResult;
}

BOOL CDataAdmin::ModifyGroupMoveFieldCheck(int nGroupNo, BOOL bView)
{
	
	BOOL bResult = FALSE;
	CString strElement;
	
	ConditionGroupInfo  stConditionGroupInfo;
	int nCondSize = 0;
	int nSize = m_arrGroups.GetSize();
	for(int i = 0; i < nSize; ++i)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);

		if(pGroup->nGroup == nGroupNo)
		{
			nCondSize = pGroup->arrConGrpInfo.GetSize();

			for(int j= 0; j < nCondSize; ++j)
			{
				stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);
				
				if((stConditionGroupInfo.stOneConditionInfo.bFalg == TRUE) && (stConditionGroupInfo.stOneConditionInfo.bFieldState == TRUE))
				{
					stConditionGroupInfo.stOneConditionInfo.bFieldVal = bView;
					stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.bView = bView;
					
					stConditionGroupInfo.strElement.TrimLeft();
					stConditionGroupInfo.strElement.TrimRight();

					bResult = ModifyOneCondition(stConditionGroupInfo.strElement, stConditionGroupInfo.stOneConditionInfo);
				}
			}
		}
	}

	return bResult;
}

BOOL CDataAdmin::ModifyConditionMoveFieldCheck(CString strElement, BOOL bView)
{
	BOOL bResult = FALSE;
	ConditionGroupInfo  stConditionGroupInfo;
    
	OneConditionInfo stCodition;
	if (GetElementToOneConditionInfo(strElement, stCodition))
	{
		if (stCodition.bFieldState == TRUE)
		{
			stCodition.bFieldVal = bView;
			stCodition.stHeadMoveInfo.bView = bView;

			bResult = ModifyOneCondition(strElement, stCodition);
		}
	}

	return bResult;
}

void CDataAdmin::DebugMoveFiledInfo()
{
	CString strTemp;

	POSITION pos;
	ConditionGroupInfo  stConditionGroupInfo;

	for (int nIndex = 0; nIndex < m_listConditionGroup.GetCount(); nIndex++)
	{
		pos = m_listConditionGroup.FindIndex(nIndex);
		stConditionGroupInfo = m_listConditionGroup.GetAt(pos);

		strTemp.Format("\n# Condition Flag : %d, FieldVal : %d, FieldState : %d, FieldEnableVal : %d",
										stConditionGroupInfo.stOneConditionInfo.bFalg,
										stConditionGroupInfo.stOneConditionInfo.bFieldVal,
										stConditionGroupInfo.stOneConditionInfo.bFieldState,
										stConditionGroupInfo.stOneConditionInfo.bFieldEnable);

		TRACE(strTemp);
	}
}


BOOL CDataAdmin::ModifyConditionNotCheck(CString strElement, int nNot)
{
	BOOL bResult = FALSE;
	OneConditionInfo stCodition;

	if (GetElementToOneConditionInfo(strElement, stCodition))
	{
		if (nNot == 0)
			stCodition.stCondition.Reverse = '0';
		else
			stCodition.stCondition.Reverse = '1';

		bResult = ModifyOneCondition(strElement, stCodition);
	}

	return bResult;
}


BOOL CDataAdmin::ModifyConditionUserDefine(CString strElement, User_Define stCondition, CString strText)
{
	BOOL bResult = FALSE;
	ConditionGroupInfo  stConditionGroupInfo;
	
	if (GetElementToGroup(strElement, stConditionGroupInfo))
	{
		
		memcpy(stConditionGroupInfo.stOneConditionInfo.stCondition.giType,    stCondition.giType,    sizeof(stCondition.giType   ));
		memcpy(stConditionGroupInfo.stOneConditionInfo.stCondition.giType2,   stCondition.giType2,   sizeof(stCondition.giType2  ));
		memcpy(stConditionGroupInfo.stOneConditionInfo.stCondition.giTrend,   stCondition.giTrend,   sizeof(stCondition.giTrend  ));
		memcpy(stConditionGroupInfo.stOneConditionInfo.stCondition.giRank,    stCondition.giRank,    sizeof(stCondition.giRank   ));

		stConditionGroupInfo.stOneConditionInfo.stCondition.Reverse = stCondition.Reverse;

		CString strType;
		strType = GetString(stConditionGroupInfo.stOneConditionInfo.stCondition.giType, sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giType));

		if(strType.Left(2).CompareNoCase("-2") == 0 || strType.Left(2).CompareNoCase("-3") == 0 ||
			strType.Left(2).CompareNoCase("-4") == 0)
		{
			memcpy(stConditionGroupInfo.stOneConditionInfo.stCondition.giType1, stCondition.giType1, sizeof(stCondition.giType1));
		}
		
		if (stConditionGroupInfo.stOneConditionInfo.bFalg == TRUE)
		{
			if ((stConditionGroupInfo.stOneConditionInfo.bFieldState == TRUE) && (stCondition.Reverse == '0'))
				stConditionGroupInfo.stOneConditionInfo.bFieldEnable = FALSE;
			else
			{
				stConditionGroupInfo.stOneConditionInfo.bFieldEnable = TRUE;
				stConditionGroupInfo.stOneConditionInfo.bFieldVal = FALSE;
			}
		}
		else
		{
			if ((stConditionGroupInfo.stOneConditionInfo.bFieldState == TRUE) && (stCondition.Reverse == '1'))
				stConditionGroupInfo.stOneConditionInfo.bFieldVal = FALSE;
			
			stConditionGroupInfo.stOneConditionInfo.bFieldEnable = TRUE;
		}

		stConditionGroupInfo.stOneConditionInfo.stCondition.IdxContiGubun = stCondition.IdxContiGubun;
		
		if (stConditionGroupInfo.nGroup == 0)
		{
			memcpy(stConditionGroupInfo.stOneConditionInfo.stCondition.giSTerm, stCondition.giSTerm, sizeof(stCondition.giSTerm));
			memcpy(stConditionGroupInfo.stOneConditionInfo.stCondition.giETerm, stCondition.giETerm, sizeof(stCondition.giETerm));
		}

		memcpy(stConditionGroupInfo.stOneConditionInfo.stCondition.giSignalCnt1, stCondition.giSignalCnt1, sizeof(stCondition.giSignalCnt1));
		memcpy(stConditionGroupInfo.stOneConditionInfo.stCondition.giSignalCnt2, stCondition.giSignalCnt2, sizeof(stCondition.giSignalCnt2));

		// 0621 재무
		int nType = GetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giType, sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giType));
		if (nType == 4001 ||nType == 4002 || nType == 4003 ||nType == 4004)
		{
			memcpy(&stConditionGroupInfo.stOneConditionInfo.stCondition.IndexType, &stCondition.IndexType, sizeof(stCondition.IndexType));
		}

		
		memcpy(&stConditionGroupInfo.stOneConditionInfo.stCondition.Code, &stCondition.Code, sizeof(stCondition.Code));

		int nIndex;
		for (nIndex = 0; nIndex < MAX_PARAM; nIndex++)
		{
			memcpy(&stConditionGroupInfo.stOneConditionInfo.stCondition.Param[nIndex], &stCondition.Param[nIndex], 
				sizeof(stCondition.Param[nIndex]));
		}
		
		for (nIndex = 0; nIndex < MAX_CONDI; nIndex++)
		{
			memcpy(&stConditionGroupInfo.stOneConditionInfo.stCondition.Condition[nIndex], &stCondition.Condition[nIndex],
				sizeof(stCondition.Condition[nIndex]));

		}
		
		stConditionGroupInfo.stOneConditionInfo.strText = strText;
		bResult = ModifyOneCondition(strElement, stConditionGroupInfo.stOneConditionInfo);
	}

	return bResult;
}

BOOL CDataAdmin::CheckCondiGubunState(CString strTagID)
{
	BOOL bResult = FALSE;
	
	if (strTagID.Left(1) == "Y")
	{
		if ((strTagID.Compare("Y1_6") == 0) ||
			(strTagID.Compare("Y1_23") == 0) ||
			(strTagID.Compare("Y1_29") == 0) ||
			(strTagID.Compare("Y2_3") == 0))
			bResult = FALSE;
		else
			bResult = TRUE;
	}
	
	return bResult;
}

BOOL CDataAdmin::ModifyConditionInsertGroup(int nGroup)
{
	BOOL bResult = FALSE;
	
	POSITION posCondition;
	ConditionGroupInfo  stConditionGroupInfo;
	int nCount = m_listConditionGroup.GetCount();
	
	if (nCount == 0)
		bResult = TRUE;
	else
	{
		for (int nIndex = 0; nIndex < nCount; nIndex++)
		{
			posCondition = m_listConditionGroup.FindIndex(nIndex);
			stConditionGroupInfo = m_listConditionGroup.GetAt(posCondition);
			
			if (nGroup <= stConditionGroupInfo.nGroup)
			{
				stConditionGroupInfo.nGroup++;

				int nTemp = GetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giGroupNo, sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giGroupNo));
				nTemp++;
				SetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giGroupNo, sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giGroupNo), nTemp);
				m_listConditionGroup.SetAt(posCondition, stConditionGroupInfo);
				
				bResult = TRUE;
			}
		}
	}
	
	return bResult;
}

// 2009.11.10 -hidden-
BOOL CDataAdmin::ModifyConditionInsertUpGroup(int nIndex, int nGroup)
{
	GROUP_INFO* pGroupInfo = new GROUP_INFO;
	pGroupInfo->nGroup = nGroup;

	if(m_arrGroups.GetSize())
	{
		GROUP_INFO* pFirst = m_arrGroups.GetAt(0);
		if(pFirst->nGroup == 0)
			m_arrGroups.InsertAt(nIndex, pGroupInfo);
		else
			m_arrGroups.InsertAt(nIndex-1, pGroupInfo);
	}
	else
		m_arrGroups.Add(pGroupInfo);

	return TRUE;
}

// 2009.11.10 -hidden-
BOOL CDataAdmin::ModifyConditionInsertDownGroup(int nIndex, int nGroup)
{
	GROUP_INFO* pGroupInfo = new GROUP_INFO;
	pGroupInfo->nGroup = nGroup;

	int nSize = m_arrGroups.GetSize();
	if(nSize >= nIndex)
	{
		GROUP_INFO* pFirst = m_arrGroups.GetAt(0);
		if(pFirst->nGroup == 0)
			m_arrGroups.InsertAt(nIndex, pGroupInfo);
		else
			m_arrGroups.InsertAt(nIndex-1, pGroupInfo);
	}
	else
		m_arrGroups.Add(pGroupInfo);

	return TRUE;
}

BOOL CDataAdmin::ModifyConditionDeleteGroup(int nGroup)
{
	int nSize = m_arrGroups.GetSize();
	for(int i = 0; i < nSize; ++i)
	{
		GROUP_INFO* pGroupInfo = m_arrGroups.GetAt(i);
		if(pGroupInfo->nGroup == nGroup)
		{
			pGroupInfo->arrConGrpInfo.RemoveAll();
			delete pGroupInfo;

			m_arrGroups.RemoveAt(i);
			break;
		}
	}

	return TRUE;
}


int CDataAdmin::GetGroupCnt()
{

	int nGroupSize = 0;
	int nSize = m_arrGroups.GetSize();

	for(int i = 0; i < nSize; ++i)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);
		if(pGroup->arrConGrpInfo.GetSize())
			++nGroupSize;
	}

	return nGroupSize;
}


int CDataAdmin::GetMaxGroup()
{
	int nResult = -1;
	
	POSITION pos;
	int nCount = m_listConditionGroup.GetCount();
	ConditionGroupInfo stConditionGroupInfo;
	
	for (int i = 0; i < nCount; i++)
	{
		pos = m_listConditionGroup.FindIndex(i);
		stConditionGroupInfo = m_listConditionGroup.GetAt(pos);
		
		if (nResult < stConditionGroupInfo.nGroup)
			nResult = stConditionGroupInfo.nGroup;
	}
	
	return nResult;
}


int CDataAdmin::GetMoveFieldTotCnt(BOOL bCommonGroup/* = TRUE*/)
{

	int nResult = 0;
	int nCondSize = 0;
	ConditionGroupInfo stConditionGroupInfo;
	
	int nCount = m_arrGroups.GetSize();
	for (int i = 0; i < nCount; ++i)
	{	
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);
		nCondSize = pGroup->arrConGrpInfo.GetSize();
		for(int j = 0; j < nCondSize; ++j)
		{
			stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);
			
			if (bCommonGroup == TRUE)
			{
				if (stConditionGroupInfo.nGroup == 0)
				{
					if (stConditionGroupInfo.stOneConditionInfo.bFieldVal == TRUE)
						nResult += stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.nColCnt;
				}
			}
			else if (bCommonGroup == FALSE)
			{
				if (stConditionGroupInfo.nGroup > 0)
				{
					if (stConditionGroupInfo.stOneConditionInfo.bFieldVal == TRUE)
						nResult += stConditionGroupInfo.stOneConditionInfo.stHeadMoveInfo.nColCnt;
				}
			}
		}
	}
	
	return nResult;
}

void CDataAdmin::DeleteOneCondition(CString strElement)
{


	strElement.TrimLeft();
	strElement.TrimRight();

	ConditionGroupInfo stConditionGroupInfo;	
	int nSize = m_arrGroups.GetSize();
	for(int i = 0; i < nSize; ++i)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);
//		int nItems = pGroup->arrConGrpInfo.GetSize();
		for(int j = 0; j < pGroup->arrConGrpInfo.GetSize(); ++j)
		{
			stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);
			
			stConditionGroupInfo.strElement.TrimLeft();
			stConditionGroupInfo.strElement.TrimRight();

			if (stConditionGroupInfo.strElement.Compare(strElement) == 0)
				pGroup->arrConGrpInfo.RemoveAt(j);
		}
	}
}

void CDataAdmin::DeleteGroup(int nGroup)
{
	int nSize = m_arrGroups.GetSize();
	for(int i = 0; i < nSize; ++i)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);
		if(pGroup->nGroup == nGroup)
		{
			pGroup->arrConGrpInfo.RemoveAll();
			delete pGroup;

			m_arrGroups.RemoveAt(i);
			break;
		}
	}
}


int CDataAdmin::GetGroupToConditionCnt(int nGroup, BOOL bException/* = TRUE*/)
{
	int nResult = 0;
	
	ConditionGroupInfo  stConditionGroupInfo;
	int nCount = m_arrGroups.GetSize();

	for (int i = 0; i < nCount; i++)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);
		if (pGroup->nGroup == nGroup)
		{
			int nCondSize = pGroup->arrConGrpInfo.GetSize();
			for(int j = 0; j < nCondSize; ++j)
			{
				stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);
				if (bException == TRUE)
				{
					if (stConditionGroupInfo.stOneConditionInfo.bFalg == TRUE)
						nResult++;
				}
				else
					nResult++;
			}
		}
	}

	return nResult;
}

int CDataAdmin::GetConditionCnt()
{
	int nViewCnt = 0;
	int nSize = m_arrGroups.GetSize();

	for(int i = 0; i < nSize; ++i)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);
		nViewCnt += pGroup->arrConGrpInfo.GetSize();
	}
	
	return nViewCnt;
}

int CDataAdmin::GetLanguageConditionCnt()
{
	int nResult = 0;
	int nCondSize = 0;

	ConditionGroupInfo  stConditionGroupInfo;
	int nSize = m_arrGroups.GetSize();

	for (int i = 0; i < nSize; ++i)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);
		nCondSize = pGroup->arrConGrpInfo.GetSize();
			
		for(int j = 0; j < nCondSize; ++j)
		{
			stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);
        
			if (stConditionGroupInfo.stOneConditionInfo.strTag == (CString)TAG_TYPE_LANGUAGE)
				nResult++;
		}
	}

	return nResult;
}

int CDataAdmin::GetConditionViewCnt()
{
	int nViewCnt = 0;
	
	int nCondSize = 0;
	ConditionGroupInfo  stConditionGroupInfo;
	int nSize = m_arrGroups.GetSize();
	
	for (int i = 0; i < nSize; i++)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);
		nCondSize = pGroup->arrConGrpInfo.GetSize();

		for(int j = 0; j < nCondSize; ++j)
		{
			stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);
        
			if (stConditionGroupInfo.stOneConditionInfo.bFalg == TRUE)
				nViewCnt++;
		}
	}
	return nViewCnt;
}


CString CDataAdmin::GetElementToTagID(CString strElement)
{
	CString strResult = "";
	ConditionGroupInfo  stConditionGroupInfo;
	
	strElement.TrimLeft();
	strElement.TrimRight();

	if(GetElementToGroup(strElement, stConditionGroupInfo))
	{
		stConditionGroupInfo.strElement.TrimLeft();
		stConditionGroupInfo.strElement.TrimRight();
		
		if (stConditionGroupInfo.strElement == strElement)
			strResult = stConditionGroupInfo.stOneConditionInfo.strTag;
	}

	return strResult;
}


BOOL CDataAdmin::GetElementToTagInfo(CString strElement,  CString &strTag, CString &strMapFile)
{
	BOOL bResult = FALSE;
	ConditionGroupInfo  stConditionGroupInfo;
	
	strElement.TrimLeft();
	strElement.TrimRight();
	
	if(GetElementToGroup(strElement, stConditionGroupInfo))
	{
		stConditionGroupInfo.strElement.TrimLeft();
		stConditionGroupInfo.strElement.TrimRight();
		
		if (stConditionGroupInfo.strElement == strElement)
		{
			strTag = stConditionGroupInfo.stOneConditionInfo.strTag;
			strMapFile = stConditionGroupInfo.stOneConditionInfo.strMapFile;
			bResult = TRUE;
		}
	}
	return bResult;
}


CString CDataAdmin::GetTagIDToElement(CString strTag)
{
	CString strResult = "";
	ConditionGroupInfo  stConditionGroupInfo;
	
	strTag.TrimLeft();
	strTag.TrimRight();
	
	int nCondSize = 0;
	int nSize = m_arrGroups.GetSize();

	for (int i = 0; i < nSize; i++)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);
		nCondSize = pGroup->arrConGrpInfo.GetSize();

		for(int j = 0; j < nCondSize; ++j)
		{
			stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);

			stConditionGroupInfo.stOneConditionInfo.strTag.TrimLeft();
			stConditionGroupInfo.stOneConditionInfo.strTag.TrimRight();

			if (stConditionGroupInfo.stOneConditionInfo.strTag == strTag)
			{
				strResult = stConditionGroupInfo.strElement;
				return strResult;
			}
		}
	}

	return strResult;
}


BOOL CDataAdmin::GetElementToUser_Define(CString strElement, User_Define &stUser_define)
{
	BOOL bResult = FALSE;
	ConditionGroupInfo  stConditionGroupInfo;
	
	strElement.TrimLeft();
	strElement.TrimRight();
	
	if(GetElementToGroup(strElement, stConditionGroupInfo))
	{		
		stConditionGroupInfo.strElement.TrimLeft();
		stConditionGroupInfo.strElement.TrimRight();
		if (stConditionGroupInfo.strElement == strElement)
		{
			stUser_define = stConditionGroupInfo.stOneConditionInfo.stCondition;
			bResult = TRUE; 
		}
	}

	return bResult;
}


BOOL CDataAdmin::GetElementToOneConditionInfo(CString strElement, OneConditionInfo  &stOneConditionInfo)
{
	BOOL bResult = FALSE;
	
	strElement.TrimLeft();
	strElement.TrimRight();

	bResult = GetElementToPosition(strElement, stOneConditionInfo);

	return bResult;
}


BOOL CDataAdmin::GetElementToPosition(CString strElement, OneConditionInfo& stCondition)
{

	// 2009.11.11 -hidden-
	BOOL bResult = FALSE;
	ConditionGroupInfo  stConditionGroupInfo;

	strElement.TrimLeft();
	strElement.TrimRight();

	int nSize = m_arrGroups.GetSize();
	for(int i = 0; i < nSize; ++i)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);
		int nItems = pGroup->arrConGrpInfo.GetSize();
		for(int j = 0; j < nItems; ++j)
		{
			stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);
			
			stConditionGroupInfo.strElement.TrimLeft();
			stConditionGroupInfo.strElement.TrimRight();
			if (stConditionGroupInfo.strElement.Compare(strElement) == 0)
			{
				stCondition = stConditionGroupInfo.stOneConditionInfo;
				bResult = TRUE; 
			}
		}
	}

	return bResult;
}

// 2009.11.11 -hidden-
BOOL CDataAdmin::GetElementToGroup(CString strElement, ConditionGroupInfo& stConditionGroup)
{
	BOOL bResult = FALSE;
	ConditionGroupInfo  stConditionGroupInfo;
	
	strElement.TrimLeft();
	strElement.TrimRight();
	
	//TraceLog("Lookup: %s\n", strElement);

	int nSize = m_arrGroups.GetSize();
	for(int i = 0; i < nSize; ++i)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);
		int nItems = pGroup->arrConGrpInfo.GetSize();
		for(int j = 0; j < nItems; ++j)
		{
			stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);
			
			stConditionGroupInfo.strElement.TrimLeft();
			stConditionGroupInfo.strElement.TrimRight();
			if (stConditionGroupInfo.strElement.Compare(strElement) == 0)
			{
				stConditionGroup = stConditionGroupInfo;
				bResult = TRUE; 

			}
			else
			{
				
			}
		}
	}
	
	return bResult;
}

BOOL CDataAdmin::GetNonAlertCondiHave(CStringArray *psaElement)
{
	BOOL bResult = FALSE;
	ConditionGroupInfo  stConditionGroupInfo;
	int nCondSize = 0;	
	int nSize = m_arrGroups.GetSize();

	for (int i = 0; i < nSize; ++i)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);
		nCondSize = pGroup->arrConGrpInfo.GetSize();

		for(int j = 0; j < nCondSize; ++j)
		{
			stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);
			
			if (stConditionGroupInfo.stOneConditionInfo.nNonAlert == 1)
			{
				psaElement->Add(stConditionGroupInfo.strElement);
				bResult = TRUE;
			}
		}
	}

	return bResult;
}

void CDataAdmin::SetNonAlertCondiDelete()
{
	ConditionGroupInfo  stConditionGroupInfo;

	int nCondSize = 0;
	int nSize = m_arrGroups.GetSize();

	for(int i = 0; i < nSize; ++i)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);
		nCondSize = pGroup->arrConGrpInfo.GetSize();
		for(int j = nCondSize-1; j > -1; --j)
		{
			stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);
			if (stConditionGroupInfo.stOneConditionInfo.nNonAlert == 1)
				pGroup->arrConGrpInfo.RemoveAt(j);
		}
	}
}

BOOL CDataAdmin::GetOnlyTargetCondition()
{

	BOOL bResult = TRUE;
	CString strTag;
	
	ConditionGroupInfo  stConditionGroupInfo;
	int nCondSize = 0;
	int nSize = m_arrGroups.GetSize();

	for (int i = 0; i < nSize; ++i)
	{
		GROUP_INFO* pGoup = m_arrGroups.GetAt(i);
		nCondSize = pGoup->arrConGrpInfo.GetSize();

		for(int j = 0; j < nCondSize; ++j)
		{
			stConditionGroupInfo = pGoup->arrConGrpInfo.GetAt(j);
			strTag = stConditionGroupInfo.stOneConditionInfo.strTag;
			strTag = strTag.Left(1);
			strTag.MakeUpper();
			
			if (strTag != "A")
				return  FALSE;
		}
	}

	return bResult;
}


int CDataAdmin::GetMinTargetBase()
{
	int nResult = 100;
	
	//# 3:1분, 4:3분, 5:5분, 6:10분, 7:15분, 8:30분, 9:60분, 0:일간, 1:주간, 2:월간 
	
	ConditionGroupInfo  stConditionGroupInfo;
	
	int nCondSize = 0;
	int nSize = m_arrGroups.GetSize();
	
	int nIndex;
	for (int i = 0; i < nSize; i++)
	{
		GROUP_INFO* pGroup = m_arrGroups.GetAt(i);
		nCondSize = pGroup->arrConGrpInfo.GetSize();

		for(int j = 0; j < nCondSize; ++j)
		{
			stConditionGroupInfo = pGroup->arrConGrpInfo.GetAt(j);
			
			
			int nTemp = GetLong(stConditionGroupInfo.stOneConditionInfo.stCondition.giTargetBase, sizeof(stConditionGroupInfo.stOneConditionInfo.stCondition.giTargetBase));
			if (nTemp >= 0 && nTemp <= 2)
				nIndex = nTemp + 10;
			else
				nIndex = nTemp;

			if (nIndex < nResult)
				nResult = nIndex;
		}
	}
	
	if (nResult >= 10)
		nResult -= 10;
	return nResult;
}


void CDataAdmin::DebugInputDataView()
{

}

BOOL CDataAdmin::ModifyConditionSwitch(CString strElement, CString strElementAfter)
{
	BOOL bResult  = FALSE;
	BOOL bResult2 = FALSE;
	ConditionGroupInfo stConditionGroupInfo;
	ConditionGroupInfo stConditionGroupInfoAfter;
    
	if (GetElementToGroup(strElement, stConditionGroupInfo) && GetElementToGroup(strElementAfter, stConditionGroupInfoAfter)) 
	{		
		bResult = ModifyOneCondition(strElement, stConditionGroupInfoAfter.stOneConditionInfo);
		bResult2 = ModifyOneCondition(strElementAfter, stConditionGroupInfo.stOneConditionInfo);
	}

	return bResult&bResult2;
}

