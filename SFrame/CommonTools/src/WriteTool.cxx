// file:        WriteTool.cxx
// created:     February 2011
//----------------------------------------------------------------------------

#include "../include/WriteTool.h"

#include <algorithm> // count

#include "TPRegexp.h"

const float GeV = 1000.0;

//____________________________________________________________________________         
WriteTool::WriteTool(SCycleBase* parent, const char* name)
  :   ToolBase(parent, name), m_first_file(1), m_meta_out(0)
{
  DeclareProperty( "connections", c_connections );
  DeclareProperty( "do_output_tree", c_do_output_tree = false);
  DeclareProperty( "output_tree_name", c_output_tree_name = "");
}

//____________________________________________________________________________         
// void WriteTool::AddObject(std::map<std::string, D3PDReader::VarBase*> &obj, std::string prefix)
// {
//   if(!IsOn()) return;
//   for( std::map<std::string, D3PDReader::VarBase*>::const_iterator itr = obj.begin(); itr != obj.end(); ++itr){
//     m_vars.insert( std::make_pair( std::string(prefix) + (*itr).first, (*itr).second ) );
//   }
// }

//____________________________________________________________________________         
void WriteTool::BeginInputData(const SInputData&) throw (SError)
{
  if(!IsOn()) return;
  //  m_meta_out = GetTree("tauPerfMeta/TrigConfTree");  
}

//____________________________________________________________________________         
void WriteTool::BeginInputFile(const SInputData& id) throw (SError)
{
    if(!IsOn()) return;
//   TTree* t = GetOutputTree( "tauPerf" );
//   for( std::map<std::string, D3PDReader::VarBase*>::iterator itr = m_vars.begin(); itr != m_vars.end(); ++itr){
//     TString varname = TString((*itr).first.c_str());
//     for( std::vector<std::string>::const_iterator sitr = c_connections.begin(); sitr != c_connections.end(); ++sitr) {
//       TPRegexp reg( (*sitr).c_str() );
//       if(varname(reg)!=varname) continue;
//       m_logger << ERROR << "Activiating " << varname << SLogger::endmsg;
//       (*itr).second->SetActive();
//       (*itr).second->WriteTo(t);
//     }
//   }

//   TTree* metadata = GetTree( "tauPerfMeta/TrigConfTree" );
//   if(m_first_file){
//     metadata->SetBranchStatus("*",1);
//     metadata->GetEntry(0);
//     m_meta_out->Branch("SMK", reinterpret_cast<int*> (metadata->GetBranch("SMK")->GetAddress()));
//     m_meta_out->Branch("HLTPSK", reinterpret_cast<int*> (metadata->GetBranch("HLTPSK")->GetAddress()));
//     m_meta_out->Branch("L1PSK", reinterpret_cast<int*> (metadata->GetBranch("L1PSK")->GetAddress()));

//     m_meta_out->Branch("HLTNameMap",  reinterpret_cast<std::map<std::string, int>** > 
// 		       (metadata->GetBranch("HLTNameMap")->GetAddress()));
//     m_meta_out->Branch("LVL1NameMap", reinterpret_cast<std::map<std::string, int>** > 
// 		       (metadata->GetBranch("LVL1NameMap")->GetAddress()));
								     
//     m_meta_out->Branch("HLTPrescaleMap", reinterpret_cast<std::map<std::string, float>** > 
// 		       (metadata->GetBranch("HLTPrescaleMap")->GetAddress()));
//     m_meta_out->Branch("LVL1PrescaleMap", reinterpret_cast<std::map<std::string, float>** > 
// 		       (metadata->GetBranch("LVL1PrescaleMap")->GetAddress()));

//     m_meta_out->Fill();
//     for(int i = 1; i != metadata->GetEntries(); ++i){
//       metadata->GetEntry(i);
//       m_meta_out->Fill();
//     }
//     m_first_file = false;
//   }
//   else{
//     metadata->CopyAddresses(m_meta_out);
//     for(int i = 0; i != metadata->GetEntries(); ++i){
//       metadata->GetEntry(i);
//       m_meta_out->Fill();
//     }    
//   }

}

//____________________________________________________________________________         
void WriteTool::EndInputData(const SInputData& id) throw (SError)
{
  for(std::map<std::string, float*>::iterator itr = m_float_vals.begin();
      itr != m_float_vals.end(); ++itr)
    delete (*itr).second;
  m_float_vals.clear();

  for(std::map<std::string, int*>::iterator itr = m_int_vals.begin();
      itr != m_int_vals.end(); ++itr)
    delete (*itr).second;
  m_int_vals.clear();

  for(std::map<std::string, bool*>::iterator itr = m_bool_vals.begin();
      itr != m_bool_vals.end(); ++itr)
    delete (*itr).second;
  m_bool_vals.clear();

  m_booked_vals.clear();
}


//____________________________________________________________________________         
void WriteTool::Write( const std::string &var_name, double val)
{
    if(!IsOn()) return;
    std::map<std::string, double*>::iterator itr = m_double_vals.find(var_name);
    if(itr==m_double_vals.end()){
      double* v = new double(val);
      m_double_vals.insert(std::make_pair(var_name, v));
      if(m_booked_vals.find(var_name) != m_booked_vals.end())
	m_logger << WARNING << "Writing Duplicate Value " << var_name << SLogger::endmsg;
      m_booked_vals.insert(var_name);
      //protect against malformed potential var names
      TString var_name_ts = var_name;      
      var_name_ts.ReplaceAll("-","_");
      GetParent()->DeclareVariable( *v, var_name_ts.Data(), c_output_tree_name.c_str() );
      return;
    }

    (*(*itr).second ) = val;
}

//____________________________________________________________________________         
void WriteTool::Write( const std::string &var_name, float val)
{
    if(!IsOn()) return;
    std::map<std::string, float*>::iterator itr = m_float_vals.find(var_name);
    if(itr==m_float_vals.end()){
      float* v = new float(val);
      m_float_vals.insert(std::make_pair(var_name, v));
      if(m_booked_vals.find(var_name) != m_booked_vals.end())
	m_logger << WARNING << "Writing Duplicate Value " << var_name << SLogger::endmsg;
      m_booked_vals.insert(var_name);
      //protect against malformed potential var names
      TString var_name_ts = var_name;      
      var_name_ts.ReplaceAll("-","_");
      GetParent()->DeclareVariable( *v, var_name_ts.Data(), c_output_tree_name.c_str() );
      return;
    }

    (*(*itr).second ) = val;
}

//____________________________________________________________________________         
void WriteTool::Write( const std::string &var_name, unsigned int val)
{
    if(!IsOn()) return;
    std::map<std::string, unsigned int*>::iterator itr = m_unsigned_int_vals.find(var_name);
    if(itr==m_unsigned_int_vals.end()){
      unsigned int* v = new unsigned int(val);
      m_unsigned_int_vals.insert(std::make_pair(var_name, v));
      if(m_booked_vals.find(var_name) != m_booked_vals.end())
	m_logger << WARNING << "Writing Duplicate Value " << var_name << SLogger::endmsg;
      m_booked_vals.insert(var_name);
      //protect against malformed potential var names
      TString var_name_ts = var_name;      
      var_name_ts.ReplaceAll("-","_");
      GetParent()->DeclareVariable( *v, var_name_ts.Data(), c_output_tree_name.c_str() );
      return;
    }

    (*(*itr).second ) = val;
}

//____________________________________________________________________________         
void WriteTool::Write( const std::string &var_name, int val)
{
    if(!IsOn()) return;
    std::map<std::string, int*>::iterator itr = m_int_vals.find(var_name);
    if(itr==m_int_vals.end()){
      int* v = new int(val);
      m_int_vals.insert(std::make_pair(var_name, v));
      if(m_booked_vals.find(var_name) != m_booked_vals.end())
	m_logger << WARNING << "Writing Duplicate Value " << var_name << SLogger::endmsg;
      m_booked_vals.insert(var_name);
      //protect against malformed potential var names
      TString var_name_ts = var_name;      
      var_name_ts.ReplaceAll("-","_");
      GetParent()->DeclareVariable( *v, var_name_ts.Data(), c_output_tree_name.c_str() );
      return;
    }

    (*(*itr).second ) = val;
}

//____________________________________________________________________________         
void WriteTool::Write( const std::string &var_name, bool val)
{
    if(!IsOn()) return;
    std::map<std::string, bool*>::iterator itr = m_bool_vals.find(var_name);
    if(itr==m_bool_vals.end()){
      bool* v = new bool(val);
      m_bool_vals.insert(std::make_pair(var_name, v));
      if(m_booked_vals.find(var_name) != m_booked_vals.end())
	m_logger << WARNING << "Writing Duplicate Value " << var_name << SLogger::endmsg;
      m_booked_vals.insert(var_name);
      //protect against malformed potential var names
      TString var_name_ts = var_name;      
      var_name_ts.ReplaceAll("-","_");
      GetParent()->DeclareVariable( *v, var_name_ts.Data(), c_output_tree_name.c_str() );
      return;
    }

    (*(*itr).second ) = val;
}

//____________________________________________________________________________         
void WriteTool::Write( const std::map<std::string, bool> &cut_results)
{
  if(!IsOn()) return;
  for(std::map<std::string, bool>::const_iterator itr = cut_results.begin(); itr != cut_results.end(); ++itr){
    Write( (*itr).first, (*itr).second );
  }
}
