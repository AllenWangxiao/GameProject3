﻿#ifndef __WS_PLAYER_OBJECT_H__
#define __WS_PLAYER_OBJECT_H__
#include "AVLTree.h"
#include "Position.h"
#include "ModuleBase.h"
#include "../Message/Msg_Game.pb.h"
#include "../ServerData/ServerDefine.h"

class CPlayerObject
{
public:
	CPlayerObject();

	~CPlayerObject();

	//  初始化玩家对象
	BOOL		Init(UINT64 u64ID);
	//  反初始化玩家对家
	BOOL		Uninit();

	BOOL		OnCreate(UINT64 u64RoleID);

	BOOL		OnDestroy();

	BOOL		OnLogin();

	BOOL		OnLogout();

	BOOL		OnNewDay();

	BOOL		ReadFromDBLoginData(DBRoleLoginAck& Ack);

	BOOL		DispatchPacket(NetPacket* pNetPack);

	BOOL		SendMsgProtoBuf(UINT32 dwMsgID, const google::protobuf::Message& pdata);
	BOOL		SendMsgRawData(UINT32 dwMsgID, const char* pdata, UINT32 dwLen);

	BOOL		ToTransferData(TransferDataReq& Req);

	BOOL		NotifyTaskEvent(UINT32 dwEventID, UINT32 dwParam1, UINT32 dwParm2);

public: //全部是操作方法
	BOOL		SendIntoSceneNotify(UINT32 dwCopyGuid, UINT32 dwCopyID, UINT32 dwSvrID);
	BOOL		SendLeaveScene(UINT32 dwCopyGuid, UINT32 dwSvrID);
	BOOL		SendRoleLoginAck();

	BOOL		SetConnectID(UINT32 dwProxyID, UINT32 dwClientID);
	BOOL		ClearCopyState();

	//模块函数
	BOOL			CreateAllModule();
	BOOL			DestroyAllModule();
	CModuleBase*	GetModuleByType(UINT32 dwModuleType);
	BOOL			OnAllModuleOK();

public:
	UINT32			CheckCopyConditoin(UINT32 dwCopyID);

public:
	UINT64			GetObjectID();
	UINT32			GetCityCopyID();


	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//计算角色，宠物， 伙伴的战斗属性
	BOOL		CalcFightDataInfo();

	INT32       m_Propertys[PROPERTY_NUM];







	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
public:
	UINT64			m_u64ID;
	UINT32			m_dwProxyConnID;
	UINT32			m_dwClientConnID;
	std::vector<CModuleBase*> m_MoudleList;

public:
	UINT32      m_dwCopyGuid;		//当前的副本ID
	UINT32      m_dwCopyID;			//当前的副本类型
	UINT32      m_dwCopySvrID;		//副本服务器的ID
	UINT32      m_dwToCopyGuid;		//正在前往的副本ID
	UINT32      m_dwToCopyID;		//正在前往的副本ID
	UINT32      m_dwToCopySvrID;	//正在前往的副本服务器的ID
};


#endif //__WS_PLAYER_OBJECT_H__
