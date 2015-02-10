// Dear emacs, this is -*- c++ -*-
#ifndef AtlasSframeUtils_SharedHandle_H
#define AtlasSframeUtils_SharedHandle_H

//Author Justin Griffiths
//Based off VarHandle Attila Krasznaa
//Generic Interface
//To Make Custom naming of variables
//Easy to make configurable data
//The advantage of this is that
//The connection of variables does not
//Hijack a previous connected variable
//And if you connect another variable
//This object will automatically take its memory

#include <TString.h>
#include <TTree.h>
#include <TBranch.h>
#include <iostream>
#include <set>

template <class Type>
class SharedHandle  {

 public:
  //Initialize Object w/ defaul trigger name
  SharedHandle( const char* name, Long64_t* master );

  ~SharedHandle();

  //Change Defaul Trigger
  void SetName(const char* name);

  //Get Simple Type
  Type operator()();

  void ReadFrom(TTree* t);

 private:
  //Additional data member that need not
  //overwrite anoter object from the base
  //class with the same name
  TString m_name;
  Long64_t* m_master;
  std::set<Type*> m_addresses;
  TTree* m_tree;
  TBranch* m_branch;

};

template <class Type>
class SharedHandle<Type*>  {
  
 public:
  //Initialize Object w/ defaul trigger name
  SharedHandle( const char* name, Long64_t* master );
  
  ~SharedHandle();
  
  //Change Defaul Trigger
  void SetName(const char* name);
  
  //Get Complex Type
  Type* operator()();
  
  void ReadFrom(TTree* t);

  
 private:
  //Additional data member that need not
  //overwrite anoter object from the base
  //class with the same name
  TString m_name;
  Long64_t* m_master;
  std::set<Type**> m_addresses;
  TTree* m_tree;
  TBranch* m_branch;

};

//////////////////////////////////////////////////
//Begin SharedHandle<Type>.icc
//////////////////////////////////////////////////
template <class Type>
SharedHandle<Type>::SharedHandle( const char* name, Long64_t* master )
  :
  m_name(name),
  m_master(master),
  m_tree(0),
  m_branch(0)
{
}
  
template <class Type>
SharedHandle<Type>::~SharedHandle() 
{
  typename std::set<Type* >::iterator itr = m_addresses.begin();
  typename std::set<Type* >::iterator itr_end = m_addresses.end();
  for(; itr != itr_end; ++itr) delete (*itr);
}
template <class Type>
void SharedHandle<Type>::SetName(const char* name) { m_name = name; }

template <class Type>
Type SharedHandle<Type>::operator()() {
  //Is the branch set?
  if( !m_branch ){    
    if( !m_tree ) {
      std::cerr << "SharedHandle.h:   NO INPUT TREE DEFINED " << std::endl;
      return Type(0);
    }
    m_branch = m_tree->GetBranch( m_name );
    if( !m_branch ) {
      std::cerr << "SharedHandle.h:   TTree: " << m_tree->GetName() << "   Has no TBranch:  " << m_name << std::endl; 
      return Type(0);
    }
  }

  //Is the branch name correct?
  if( TString(m_branch->GetName()) != m_name ) {
    if( !m_tree ) {
      std::cerr << "SharedHandle.h:   NO INPUT TREE DEFINED " << std::endl;
      return 0;
    }
    //Correct branch
    m_branch = m_tree->GetBranch( m_name );    
    if( !m_branch ) {
      std::cerr << "SharedHandle.h:   TTree: " << m_tree->GetName() << "   Has no TBranch:  " << m_name << std::endl; 
      return Type(0);
    }
  }


  //Here we either return the derefernce of m_address or
  //we connect m_trigger to the Branch and get the correct entry
  //if we connect the branch another object can later
  //replace the branh's address w/ their own
  //we don't care we always return *(m_branch->GetAddress())!
  if( !m_branch->GetAddress() ){
    //This branch has no object associated to it    
    m_tree->SetBranchStatus( m_name, 1 );
    Type* address = new Type();
    m_addresses.insert(address);
    m_tree->SetBranchAddress( m_name, address, &m_branch );
    m_branch->GetEntry( *m_master );
    return (*address);
  }

  //The branch has an address we will just return its dereference regardless
  //whether we own it or not
  if( m_branch->GetAddress() ){
    if( m_branch->GetReadEntry() != *m_master ) m_branch->GetEntry(*m_master);
    return * (reinterpret_cast<Type*> (m_branch->GetAddress()));
  }
  std::cerr << "SharedHandle.h:   No Decision made" << std::endl;
  return Type(0);

}

template <class Type>
void SharedHandle<Type>::ReadFrom(TTree* t) { m_tree = t; m_branch = 0; }
/////End SharedHandle<Type>.icc

//////////////////////////////////////////////////
//Begin SharedHandle<Type*>.icc
//////////////////////////////////////////////////

template <class Type>
SharedHandle<Type*>::SharedHandle( const char* name, Long64_t* master )
  :
  m_name(name),
  m_master(master),
  m_tree(0),
  m_branch(0)
{
}

template <class Type>
SharedHandle<Type*>::~SharedHandle()
{
  typename std::set<Type** >::iterator itr = m_addresses.begin();
  typename std::set<Type** >::iterator itr_end = m_addresses.end();
  for(; itr != itr_end; ++itr) delete (*itr);
}

template <class Type>
void SharedHandle<Type*>::SetName(const char* name) { m_name = name; }

template <class Type>
Type* SharedHandle<Type*>::operator()() {
  //Is the branch set?
  if( !m_branch ){    
    if( !m_tree ) {
      std::cerr << "SharedHandle.h:   NO INPUT TREE DEFINED " << std::endl;
      return 0;
    }
    m_branch = m_tree->GetBranch( m_name );
    if(!m_branch){
      std::cerr << "SharedHandle.h:   TTree: " << m_tree->GetName() << "   Has no TBranch:  " << m_name << std::endl; 
      return 0;
    }
  }
    
  //Is the branch name correct?
  if( TString(m_branch->GetName()) != m_name ) {
    if( !m_tree ) {
      std::cerr << "SharedHandle.h:   NO INPUT TREE DEFINED " << std::endl;
      return 0;
    }
    //Correct branch
    m_branch = m_tree->GetBranch( m_name );    
    if(!m_branch){
      std::cerr << "SharedHandle.h:   TTree: " << m_tree->GetName() << "   Has no TBranch:  " << m_name << std::endl; 
      return 0;
    }
  }
    
    
  //Here we either return the derefernce of m_address or
  //we connect m_trigger to the Branch and get the correct entry
  //if we connect the branch another object can later
  //replace the branh's address w/ their own
  //we don't care we always return *(m_branch->GetAddress())!
  if( !m_branch->GetAddress() ){
    //This branch has no object associated to it    
    m_tree->SetBranchStatus( m_name, 1 );
    Type** address = new Type*;
    (*address) = 0;
    m_addresses.insert(address);
    m_tree->SetBranchAddress( m_name, address, &m_branch );
    m_branch->GetEntry( *m_master );
    return (*address);
  }
    
  //The branch has an address we will just return its dereference regardless
  //whether we own it or not
  if( m_branch->GetAddress() ){
    if( m_branch->GetReadEntry() != *m_master ) m_branch->GetEntry(*m_master);
    return * ((reinterpret_cast<Type**> (m_branch->GetAddress()))); 
  }
  
  std::cerr << "SharedHandle.h:   No Decision made" << std::endl;
  return 0;
    
}

template <class Type>
void SharedHandle<Type*>::ReadFrom(TTree* t) { m_tree = t; m_branch = 0; }
///End SharedHandle<Type*>.icc

#endif


