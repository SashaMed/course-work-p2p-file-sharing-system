#ifndef SERVER_HEADER 
#define SERVER_HEADER

#include <bits/stdc++.h>
#include <openssl/sha.h>
#include <sys/socket.h> 
#include <sys/types.h> 
#include <signal.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <stdarg.h> 
#include <errno.h> 
#include <fcntl.h>
#include <sys/time.h> 
#include <sys/ioctl.h> 
#include <netdb.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
using namespace std; 

#define TRACKER_PORT 18000
#define ll long long int
#define MAXLINE 4096 
#define SA struct sockaddr 

extern string logFileName, tracker1_ip, tracker2_ip, curTrackerIP;
extern uint16_t tracker1_port, tracker2_port, curTrackerPort;
extern unordered_map<string, string> loginCreds; //cписок пользователей
extern unordered_map<string, bool> isLoggedIn; //список активных в данных момент пользователей
extern unordered_map<string, unordered_map<string, set<string>>> seederList; // групп айди и список файлов в группе со списком сидов
extern unordered_map<string, string> fileSize;//размер каждого файла
extern unordered_map<string, string> grpAdmins; //список админов
extern vector<string> allGroups;  //список всех групп
extern unordered_map<string, set<string>> groupMembers;  //список групп и их пользователей
extern unordered_map<string, set<string>> grpPendngRequests; //список запросов в группу
extern unordered_map<string, string> unameToPort; //айпи и порт юзер айдишников
extern unordered_map<string, string> piecewiseHash;  //хеш к каждому файлу

void handle_connection(int);
void list_files(vector<string>, int);
void stop_share(vector<string>, int, string);
void leave_group(vector<string>, int, string);
void accept_request(vector<string>, int, string);
void list_requests(vector<string>, int, string);
void join_group(vector<string>, int, string);
void list_groups(vector<string>, int);
int create_group(vector<string>, int, string);
void downloadFile(vector<string>, int, string);
void uploadFile(vector<string>, int, string);
int validateLogin(vector<string>);
int createUser(vector<string>);
void clearLog();
void writeLog(const string &);
bool pathExists(const string &s);
vector<string> splitString(string, string);
void* check_input(void*);
vector<string> getTrackerInfo(char*);
void processArgs(int, char **);

#endif