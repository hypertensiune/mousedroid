#pragma once

#include <iostream>
#include <vector>
#include <thread>

#include <stdlib.h>

#include "net_base.hpp"
#include "Client.hpp"
#include "Device.hpp"
#include "wxDeviceList.hpp"
#include "Logger.hpp"

class Server
{
    public:
        const short PORT = 6969;

        Server();
        ~Server();

        InputManager input_manager;

        void start();
        void stop();

        void setDeviceList(wxDeviceList *_wxdevlist);
        std::pair<std::string, std::string> getHostInfo();

    private:
        int currentID = 0;
        wxDeviceList *wxdevlist = nullptr;

        std::vector<std::shared_ptr<Client>> clients;

        asio::io_context context;
        asio::ip::tcp::acceptor acceptor;

        std::thread thread;

        void OnClientConnected();
        void OnClientDisconnected(std::shared_ptr<Client> client);

        void do_accept();
};