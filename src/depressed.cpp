/*
BSD 2-Clause License

Copyright (c) 2022, Mikhail Morozov
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <Windows.h>

#include "../include/depressed_document.h"
#include "../include/depressed_open.h"

INT WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	wchar_t **argv, *default_project = 0, *default_output = 0;
	int argc;
	Depressed::CDocument document;

	argv = CommandLineToArgvW(pCmdLine, &argc);
	if(!argv) return EXIT_FAILURE;

	if(argc > 0) default_project = argv[0];
	if(argc > 1) default_output = argv[1];

	SetSearchPathMode(BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE | BASE_SEARCH_PATH_PERMANENT);

	if(!document.Create()) {
		MessageBoxW(NULL, L"Can't create empty document, probably not enough memory", L"Depressed", MB_OK | MB_TASKMODAL | MB_ICONSTOP);

		return EXIT_FAILURE;
	}

	if(argc < 2) {
		// Run GUI
		MessageBoxW(NULL, L"Depressed GUI unimplemented", L"Depressed", MB_OK | MB_TASKMODAL | MB_ICONSTOP);
	} else if(argc == 2) {
		// Process project file and create djvu
		if(Depressed::OpenDied(default_project, document)) {
			if(document.Process() != Depressed::DocumentProcessStatus::OK)
				MessageBoxW(NULL, L"Can't save djvu file", L"Depressed", MB_OK | MB_TASKMODAL | MB_ICONSTOP);
		} else
			MessageBoxW(NULL, L"Can't open project file", L"Depressed", MB_OK | MB_TASKMODAL | MB_ICONSTOP);
		//MessageBoxW(NULL, L"Project processing unimplemented", L"Depressed", MB_OK | MB_TASKMODAL | MB_ICONSTOP);
	} else {
		MessageBoxW(NULL, L"Too many arguments", L"Depressed", MB_OK | MB_TASKMODAL | MB_ICONINFORMATION);
	}
	
	document.Destroy();

	LocalFree(argv);

	return 0;
}
