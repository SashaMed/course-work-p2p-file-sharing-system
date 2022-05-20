#ifndef CLIENT_HEADER 
#define CLIENT_HEADER

#include <bits/stdc++.h>
#include <openssl/sha.h>
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/stat.h>

using namespace std;

#define FILE_SEGMENT_SZ 524288
#define SIZE 32768
#define SA struct sockaddr 
#define ll long long int

extern string logFileName, tracker1_ip, tracker2_ip, peer_ip;
extern uint16_t peer_port, tracker1_port, tracker2_port;
extern unordered_map<string, string> downloadedFiles; //загруженные файлы, айди группы и файлы
extern bool loggedIn; 
extern bool isCorruptedFile;
extern unordered_map<string, unordered_map<string, bool>> isUploaded; //список загрузок айди группы, имя файла и флаг загрузки 
extern unordered_map<string, vector<int>> fileChunkInfo;
extern vector<vector<string>> curDownFileChunks;
extern unordered_map<string, string> fileToFilePath; //список файлов с путями к ним
extern vector<string> curFilePiecewiseHash; //

string getHash(char*);
string getFileHash(char*);
long long file_size(char*);
void writeLog(const string &);
void getStringHash(string, string&);
void writeLog(const string &);
void clearLog();
vector<string> splitString(string, string);
vector<string> getTrackerInfo(char*);
void setChunkVector(string, ll, ll, bool);
void processArgs(int, char **);
void sendChunk(char*, int, int);
int writeChunk(int, ll cnkNum, char*);
void handleClientRequest(int);
string connectToPeer(char*, char*, string);
void* runAsServer(void*);
void piecewiseAlgo(vector<string>, vector<string>);
int downloadFile(vector<string>, int);
int uploadFile(vector<string>, int);
int list_groups(int);
int list_requests(int);
void accept_request(int);
void leave_group(int);
void show_downloads();
void list_files(int);
int processCMD(vector<string>, int);
int connectToTracker(int, struct sockaddr_in &, int);
bool pathExists(const string &s);
void printHelp();

#endif