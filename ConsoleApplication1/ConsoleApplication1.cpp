#include <windows.h>
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <tchar.h>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    int processCount = 0;
    string check;
    double a = 1;
    double b = 7;
    int totalN = 100000;
    const char* filePath = "output.txt";
    std::ofstream outputFile(filePath);

    cout << "Do you want to set amount of proceses ? (yes or no) ";
    cin >> check;
    vector<HANDLE> process_handles;
   
    if (check == "yes") {
        cout << "Enter amount of proceses: ";
        cin >> processCount;
        cout << "Enter first and second border: ";
        cin >> a >> b;
        cout << "Enter amount of steps: ";
        cin >> totalN;
        struct timespec start2;
        timespec_get(&start2, TIME_UTC);

        for (int i = 0; i < processCount; ++i) {
            double start = a + i * ((b - a) / processCount);
            double end = start + ((b - a) / processCount);
            int numN = totalN / processCount;

            STARTUPINFO si = {};
            PROCESS_INFORMATION pi = {};

            ZeroMemory(&si, sizeof(si));
            si.cb = sizeof(si);

            wchar_t cmdLine[256];
            _snwprintf_s(cmdLine, sizeof(cmdLine), L"E:\\Slavery\\ONLY_FANS\\2curs\\OS-lab\\lab-3\\ConsoleApplication2\\x64\\Debug\\ConsoleApplication2.exe %f %f %d", start, end, numN);

            if (CreateProcess(NULL, cmdLine, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
                printf("pid=%d, tid=%d\n", pi.dwProcessId, pi.dwThreadId);
                outputFile << "pid = " << pi.dwProcessId << "tid = " << pi.dwThreadId << std::endl;
                process_handles.push_back(pi.hProcess);
                CloseHandle(pi.hThread);
            }
            else {
                std::cerr << "Error creating process: " << GetLastError() << std::endl;
                return 1;
            }
        }

        for (HANDLE handle : process_handles) {
            WaitForSingleObject(handle, INFINITE);
            CloseHandle(handle);
        }

        struct timespec end2;
        timespec_get(&end2, TIME_UTC);

        double walltime = (end2.tv_sec - start2.tv_sec) + (end2.tv_nsec - start2.tv_nsec) / 1000000000.0;

        outputFile << "Time of execution :" << walltime << "s \n" << endl;
    }
    else {

        processCount = 1;
        double* time_count;
        time_count = new double[6];

        for (int j = 1; j < 12; ++j) {

            struct timespec start2;
            timespec_get(&start2, TIME_UTC);

            for (int i = 0; i < processCount; ++i) {
                double start = a + i * ((b - a) / processCount);
                double end = start + ((b - a) / processCount);
                int numN = totalN / processCount;

                STARTUPINFO si = {};
                PROCESS_INFORMATION pi = {};

                ZeroMemory(&si, sizeof(si));
                si.cb = sizeof(si);

                wchar_t cmdLine[256];
                _snwprintf_s(cmdLine, sizeof(cmdLine), L"E:\\Slavery\\ONLY_FANS\\2curs\\OS-lab\\lab-3\\ConsoleApplication2\\x64\\Debug\\ConsoleApplication2.exe %f %f %d", start, end, numN);

                if (CreateProcess(NULL, cmdLine, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
                    printf("pid=%d, tid=%d\n", pi.dwProcessId, pi.dwThreadId);
                    outputFile << "pid = " << pi.dwProcessId << "tid = " << pi.dwThreadId << std::endl;
                    process_handles.push_back(pi.hProcess);
                    CloseHandle(pi.hThread);
                }
                else {
                    std::cerr << "Error creating process: " << GetLastError() << std::endl;
                    return 1;
                }
            }

            for (HANDLE handle : process_handles) {
                WaitForSingleObject(handle, INFINITE);
                CloseHandle(handle);
            }

            struct timespec end2;
            timespec_get(&end2, TIME_UTC);

            double walltime = (end2.tv_sec - start2.tv_sec) + (end2.tv_nsec - start2.tv_nsec) / 1000000000.0;

            outputFile << "Time of execution :" << walltime << "s \n" << endl;
            time_count[j - 1] = walltime;
            processCount++;
        }

        int k = 0;
        double min_count = 100;
        for (int j = 0; j < 6; ++j) {
            if (min_count > time_count[j]) {
                min_count = time_count[j];
                k = j + 1;
            }
        }
        outputFile << "The most efficient way to perform this process in: " << k << "threads" << endl;
    }
    outputFile.close();

    return 0;
}