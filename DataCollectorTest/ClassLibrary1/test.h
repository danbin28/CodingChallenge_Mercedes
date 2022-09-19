#pragma once
ref class DataCollector
{
public:
	int static Run();

private:
	void createTar(std::string filename);
    static void OnChanged(Object^ sender, FileSystemEventArgs^ e);
    static void OnCreated(Object^ sender, FileSystemEventArgs^ e);
    static void OnDeleted(Object^ sender, FileSystemEventArgs^ e);
    static void OnRenamed(Object^ sender, RenamedEventArgs^ e);
    static void OnError(Object^ sender, ErrorEventArgs^ e);
    static void PrintException(Exception^ ex);
};


