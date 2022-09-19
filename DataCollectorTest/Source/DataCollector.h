#pragma once
#include "pch.h"
#include <string>
#include <iostream>
#include <vector>

class DataCollector
{
public:
	int static Run();

private:
    System::String^                 initPath();
    std::vector<System::String^>    initData();
    static void                     OnChanged(Object^ sender, FileSystemEventArgs^ e);
    static void                     OnCreated(Object^ sender, FileSystemEventArgs^ e);
    static void                     OnRenamed(Object^ sender, RenamedEventArgs^ e);
    static void                     changeTriggerPath(FileSystemWatcher^ watcher, DataCollector* DC);
    static void                     createTrigger(FileSystemWatcher^ watcher, System::String^ path, System::String^ filter);
    static void                     setTriggerPath(FileSystemWatcher^ watcher, System::String^ path);
    static void                     createDriveInfoFile();
};


