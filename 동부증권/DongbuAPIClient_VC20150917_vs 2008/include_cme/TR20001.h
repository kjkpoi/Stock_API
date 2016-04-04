/**************************************************************/
/*  ���α׷����    : {CME���� �ֹ� }       				  */
/**************************************************************/

#ifndef _DEFINEDLL_TR20001_
#define	_DEFINEDLL_TR20001_

typedef struct
{
    char    incnt    [ 4];       /* �ֹ� cnt                 */
    char    mapno    [ 5];       /* TR����ϴ� Map��ȣ       */
} TR_20001_I;

typedef struct
{
    char    clikey  [ 8];		/* �ֹ� key                                 */
    char    gb      [ 1];		/* 1:�ŵ�, 2:�ż�,  3:����, 4:���          */
    char    geja	[20];		/* ���¹�ȣ                                 */
    char    passwd	[ 8];		/* ��й�ȣ                                 */
    char    code	[15];		/* �����ڵ�                                 */
    char    wonno	[ 9];		/* ���ֹ���ȣ   S9(9)                       */
    char    jutype	[ 2];		/* �����ɼ�ȣ�������ڵ�                */
                                /* 00:������ 03:���尡 05:���Ǻ�������      */
                                /* 06:������������                          */
    char    juprc	[12];		/* �ֹ���     S9(9).99 ->�Ҽ�������         */
    char    qty		[15];		/* �ֹ�����   S9(15)                        */
    char    ip      [16];		/* Ŭ���̾�Ʈ IP�ּ�(��: 192009101031)      */
} TR_20001_IS; //106

typedef struct 
{
    char    outcnt   [ 4];       /* �ֹ���ȣ cnt              */
} TR_20001_O;

typedef struct
{
    char    clikey   [ 8];       /* �ֹ� key                  */
    char    lOrdNo   [ 9];       /* �ֹ���ȣ   S9(9)          */
    char    msgcd    [ 6];       /* �޽����ڵ�                */
    char    msgcm   [100];       /* ó���޽���                */
} TR_20001_OS;

#endif