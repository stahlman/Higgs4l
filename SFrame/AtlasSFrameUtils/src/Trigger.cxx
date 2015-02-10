#include "../include/Trigger.h"
#include <iostream>

ClassImp( Trigger )

using std::cout;
using std::endl;
using std::cerr;

Trigger::Trigger(Long64_t &master, const char* name, const D3PDReader::TriggerD3PDObject &parent)
  :
    D3PDReader::TriggerD3PDObject(parent),
    CurrentTrigger( name, &master )
{
  
}


Trigger::~Trigger(){}

void Trigger::ReadFrom( ::TTree* tree ){
  D3PDReader::TriggerD3PDObject::ReadFrom( tree );
  CurrentTrigger.ReadFrom( tree );
}
