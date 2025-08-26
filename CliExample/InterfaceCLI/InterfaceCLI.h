#pragma once


//This is a completely valid pure C++ header. Nothing from CLI/C++ syntax is allowed here. This Header can therfore be included in native C++ code (code that does not have the /clr compiler flag set
// Lessons learned: If we use a CLI/C++ Header (with ref class etc) that is not a "normal" header file! E.g. including that file and linking it, may lead to duplicated declarations of the same class. 
//(https://stackoverflow.com/questions/2977534/c-cli-public-ref-struct-generates-c2011-class-type-redefinition)
//Lessons learned: Visual Studio: C++/CLI-support for v143-Buildtools (newest) is an additional component that has to be installed manually!
//Lessons learned: Visual studio has better support for project files changes and for link and CLI/C++ errors!

class CSharpInterface;

//__declspec(dllexport) to make this class visible in the consuming code
class __declspec(dllexport) CppCliWrapper
{
public:
	CppCliWrapper();
	~CppCliWrapper();

	/* To marchall a std::string is not supported natively, so use wstring
	* https://learn.microsoft.com/en-us/cpp/dotnet/overview-of-marshaling-in-cpp?view=msvc-170
	*/

	virtual void SendDataToCSharp(std::wstring text);

	//For large pictures a file path might be a better solution. 
	void SendPointer(wchar_t* bytearray);
private:
	CSharpInterface* _managedState;
};
