
#include "HeadTail.h"


HeadTail::HeadTail() : Uniform()
{

}


HeadTail::~HeadTail()
{
}

double HeadTail::Generate()
{
	return (Uniform.Generate() <= 0.5);
}