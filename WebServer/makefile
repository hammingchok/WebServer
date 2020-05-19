CXX ?= g++

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CXXFLAGS += -g
else
    CXXFLAGS += -O2

endif

server: main.cpp  timer.cpp http_conn.cpp log.cpp database_connection_pool.cpp  webserver.cpp config.cpp
	$(CXX) -o server  $^ $(CXXFLAGS) -lpthread -lmysqlclient

CGISQL.cgi:sign.cpp
	g++ -o ./root/CGISQL.cgi $^ -lpthread -lmysqlclient

clean:
	rm  -r server
	rm  -r ./root/CGISQL.cgi
