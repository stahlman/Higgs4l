#ifndef AtlasSFrameUtils_Trigger_H
#define AtlasSFrameUtils_Trigger_H

//author Justin Griffiths

#include "TriggerD3PDObject.h"
#include "SharedHandle.h"

//If we decide to have L1 and L2 Trigger Objects
//Then we can make this more general like
//ParticleElement

class Trigger : public D3PDReader::TriggerD3PDObject {

 public:
  //Initialize Object w/ defaul trigger name
  Trigger(Long64_t &master, const char* name, const D3PDReader::TriggerD3PDObject &parent);
  ~Trigger();

  void ReadFrom( ::TTree* tree );
    
    
  SharedHandle<Bool_t> CurrentTrigger;
    
  ClassDef( Trigger, 0 )
      
    };

  
#endif
