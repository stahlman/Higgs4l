// file:      WriteTool.h
// created:   February 2011
//------------------------------------------------------------------------------

#ifndef CommonTools_WriteTool_h
#define CommonTools_WriteTool_h

#include <vector>
#include <string>
#include <set>
#include <map>

#include "ToolBase.h"
#include "VarHandle.h"

#include "TTree.h"

class WriteTool : public ToolBase
{
    public:
        WriteTool(SCycleBase* parent, const char* name);
	void BeginInputFile( const SInputData& ) throw (SError);
	void BeginInputData( const SInputData& ) throw (SError);
	void EndInputData( const SInputData& ) throw (SError);

	//	void AddObject(std::map<std::string, D3PDReader::VarBase*> &obj, std::string prefix);
	void Write( const std::string &var_name, double val);
	void Write( const std::string &var_name, float val);
	void Write( const std::string &var_name, unsigned int val);
	void Write( const std::string &var_name, int val);
	void Write( const std::string &var_name, bool val);
	void Write( const std::map<std::string, bool> &cut_results);

	inline bool IsOn() {return c_do_output_tree;}
	inline std::string GetOutputTreeName() {return c_output_tree_name;}

    private:
	std::vector<std::string> c_connections;
	//	std::map<std::string, D3PDReader::VarBase*> m_vars;
	std::map<std::string, double*> m_double_vals;
	std::map<std::string, float*> m_float_vals;
	std::map<std::string, unsigned int*> m_unsigned_int_vals;
	std::map<std::string, int*> m_int_vals;
	std::map<std::string, bool*> m_bool_vals;
	std::set<std::string> m_booked_vals;
	bool c_do_output_tree;
	std::string c_output_tree_name;

	bool m_first_file;
	TTree* m_meta_out;
	

}; // class WriteTool

#endif // CommonTools_WriteTool_h
