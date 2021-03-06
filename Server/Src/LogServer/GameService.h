﻿#ifndef _GAME_SERVICE_H_
#define _GAME_SERVICE_H_
#include "ServiceBase.h"
#include "LogMsgHandler.h"

class CGameService : public IPacketDispatcher
{
private:
	CGameService(void);
	virtual ~CGameService(void);

public:
	static CGameService* GetInstancePtr();

	BOOL		Init();

	BOOL		Uninit();

	BOOL		Run();

	BOOL		OnNewConnect(CConnection *pConn);

	BOOL		OnCloseConnect(CConnection *pConn);

	BOOL		DispatchPacket( NetPacket *pNetPacket);

public:

	CLogMsgHandler		m_LogMsgHandler;
};

#endif
