//********************************************************************************************
//Developer: Sergiy Stoyan
//        s.y.stoyan@gmail.com
//        sergiy.stoyan@hotmail.com
//        http://www.cliversoft.com
//********************************************************************************************

#ifndef Writer_H
#define Writer_H


#include "Database.h"
#include "utils.h"
#include "Websocket.Server.h"

class Writer
{
public:

	Writer()
	{
	}

	~Writer()
	{
		try
		{
			Close();
		}
		catch (...)
		{
			STDOUT_CURRENT_EXCEPTION("Close()");
		}
	}

	void Close();
	void Run();

protected:
	Database* database = NULL;
	Websocket::Server* server = NULL;
	void initialize();

	sql::PreparedStatement* sth_upd_sync_head = NULL;
	sql::PreparedStatement* sth_fork_bkp = NULL;
	sql::PreparedStatement* sth_upd_sync_fork = NULL;
	sql::PreparedStatement* sth_check_sync_health = NULL;
	sql::PreparedStatement* sth_am_i_master = NULL;
	sql::PreparedStatement* sth_clean_bkp = NULL;
	sql::PreparedStatement* sth_prune_transactions = NULL;
	sql::PreparedStatement* sth_prune_receipts = NULL;
	sql::PreparedStatement* sth_fetch_forking_traces = NULL;
	sql::PreparedStatement* sth_fork_receipts = NULL;
	sql::PreparedStatement* sth_fork_transactions = NULL;
};

#endif //Writer_H
