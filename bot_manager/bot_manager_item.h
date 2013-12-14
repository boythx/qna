//
//
#pragma once

#include "../bot_packet/bot_packet.h"

class bot_manager_item;
#include "bot_manager.h"
#include "Game.h"



class bot_manager_item
{
public:
	bot_manager_item(bot_manager* mngr, const char* name, const char* work_dir);
	~bot_manager_item();

 	bool startup();
 	void cleanup();
 	void on_push_event(bot_exchange_format f);
	void send_to_module(const char *module_id, bot_exchange_format &f);

	bool disable;
private:
	Game game;
	void apply_changes();
	
	bot_manager *_mngr;
	
	std::string _name;
	std::string _work_dir;
	
	std::string _message;
	std::string _message_copy;

	char _config_full_path[2600];

};
