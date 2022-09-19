#include "pch.h"
#include "test.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "tarball.h"

using namespace System;
using namespace System::IO;

class DataCollector
{
public:

    static int DataCollector::Run()
    {
        // Create variables 
        System::String^ userinput;
        System::String^ path;

        // Set default filter for filenames
        System::String^ filter = "core*.lz4";
       
        // Wait for user Input for the path to watch
        path = DataCollector::init();

        // Create FileSystemWatcher fot the trigger function on Windows
        FileSystemWatcher^ watcher = gcnew FileSystemWatcher(path);

        // Create Trigger
        DataCollector::createTrigger(watcher, path, filter);

        // Program loop until the user ends it
        do {
            Console::WriteLine("Press e to exit.");
            Console::WriteLine("Press c to change directory.");
            userinput = Console::ReadLine();

            // Case if the user wants to change the directory
            if (userinput == "c") {
                DataCollector::changeTriggerPath(watcher);
            }

            // Every wrong or invalid input
            else if (userinput != "e") {
                Console::WriteLine("Please choose one of the following options:");
            }


        // Do this while the user dont press "e" for exit
        } while (userinput != "e" );
        

        return 0;
    }

private:

    static System::String^ DataCollector::init()
    {
        Console::WriteLine("Please insert the new directory to monitor. It has to be in the format: D:\\Example\\Folder\\Test");
        return(Console::ReadLine());
    }

    static void DataCollector::changeTriggerPath(FileSystemWatcher^ watcher)
    {
        Console::WriteLine("Please insert the new directory to monitor. It has to be in the format: D:\\Example\\Folder\\Test");
        DataCollector::setTriggerPath(watcher, Console::ReadLine());
        watcher->Path = Console::ReadLine();
        Console::WriteLine("Changed Path to:" + watcher->Path);
    }

    static void DataCollector::createTrigger(FileSystemWatcher^ watcher, System::String^ path, System::String^ filter)
    {
        watcher->NotifyFilter = static_cast<NotifyFilters>(NotifyFilters::Attributes
            | NotifyFilters::CreationTime
            | NotifyFilters::DirectoryName
            | NotifyFilters::FileName
            | NotifyFilters::LastAccess
            | NotifyFilters::LastWrite
            | NotifyFilters::Security
            | NotifyFilters::Size);

        watcher->Changed += gcnew FileSystemEventHandler(DataCollector::OnChanged);
        watcher->Created += gcnew FileSystemEventHandler(DataCollector::OnCreated);
        watcher->Renamed += gcnew RenamedEventHandler(DataCollector::OnRenamed);

        watcher->Filter = filter;
        watcher->IncludeSubdirectories = true;
        watcher->EnableRaisingEvents = true;
    }

    static void DataCollector::setTriggerPath(FileSystemWatcher^ watcher, System::String^ path)
    {
        watcher->Path = path;
        Console::WriteLine("Changed Path to:" + watcher->Path);
    }

    static void DataCollector::OnChanged(Object^ sender, FileSystemEventArgs^ e)
    {
        if (e->ChangeType != WatcherChangeTypes::Changed)
        {
            return;
        }
        Console::WriteLine("Changed: {0}", e->FullPath);
        Console::WriteLine("Collecting data...");
    }

    static void DataCollector::OnCreated(Object^ sender, FileSystemEventArgs^ e)
    {
        Console::WriteLine("Created: {0}", e->FullPath);
        Console::WriteLine("Collecting data...");
    }


    static void DataCollector::OnRenamed(Object^ sender, RenamedEventArgs^ e)
    {
        Console::WriteLine("Renamed:");
        Console::WriteLine("    Old: {0}", e->OldFullPath);
        Console::WriteLine("    New: {0}", e->FullPath);
        Console::WriteLine("Collecting data...");
    }

    /*
    static void DataCollector::createTar(std::string filename)
    {
        std::fstream out(filename, std::ios::out);
        if (!out.is_open())
        {
            Console::WriteLine("Cannot open out tar File");
        }
        // create the tar file
        lindenb::io::Tar tarball(out);
    }

    static void DataCollector::addItemTar(std::string filename)
    {
        tarball.put("myfiles/item1.txt", "Hello World 1\n");
    }
    */
};


int main()
{
    
    DataCollector::Run();

    return 0;
}


