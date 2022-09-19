#pragma once
ref class DataCollector
{
public:
	int static Run();

private:
	//void createTar(std::string filename);
    static void                             OnChanged(Object^ sender, FileSystemEventArgs^ e);
    static void                             OnCreated(Object^ sender, FileSystemEventArgs^ e);
    static void                             OnRenamed(Object^ sender, RenamedEventArgs^ e);
    static System::String^                  initPath();
    static std::vector<System::String^>     initData();
    static void                             changeTriggerPath(FileSystemWatcher^ watcher);
    static void                             createTrigger(FileSystemWatcher^ watcher, System::String^ path, System::String^ filter);
    static void                             setTriggerPath(FileSystemWatcher^ watcher, System::String^ path);
};


