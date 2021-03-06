﻿#include "stdafx.h"
#include "CommandDef.h"
#include "LogMsgHandler.h"
#include "CommonFunc.h"
#include "CommonEvent.h"
#include "GameService.h"
#include "PacketHeader.h"
#include "CommonSocket.h"

CLogMsgHandler::CLogMsgHandler()
{

}

CLogMsgHandler::~CLogMsgHandler()
{

}

BOOL CLogMsgHandler::Init(UINT32 dwReserved)
{
	return TRUE;
}

BOOL CLogMsgHandler::Uninit()
{
	return TRUE;
}



BOOL CLogMsgHandler::DispatchPacket(NetPacket* pNetPacket)
{
	switch(pNetPacket->m_dwMsgID)
	{
		case 4999998:
			OnTestMsgReq(pNetPacket);
			break;
		default:
		{

		}
		break;
	}

	return TRUE;
}






BOOL CLogMsgHandler::OnTestMsgReq(NetPacket* pNetPacket)
{
	char sz[20] = "abcdefghiji";

	ServiceBase::GetInstancePtr()->SendMsgRawData(pNetPacket->m_dwConnID, 12345, 0, 0, sz, 20);

	return TRUE;
}
