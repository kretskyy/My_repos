#include"Error.h"
#include<string>
using namespace std;

Error::Error(ErrorCode code)
{
	this->code = code;
}

string Error::ToString()
{
	switch (code)
	{
	case NegativeValue:
		return "Value is negative";
	case IdxOutsideLimit:
		return "Index is outside the limit";
	case MaxSizeReached:
		return "Max size is reached";
	default:
		break; 
	}
}