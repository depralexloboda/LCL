#ifndef LAMBDA_HPP
#define LAMBDA_HPP
#include <string>
#include <set>
#include <map>
#include <ostream>

namespace lambda_calculus{
	using std::string;
	using std::ostream;
	using std::set;
	using std::map;
	
	class variable;
	
	class parser_exception{
		int pos;
		string str;
		string cause;
	public:
		parser_exception(string str, string cause, int pos);
		string message();
	};
	
	class lambda_impl{
	public:
		virtual ~lambda_impl(){}
		virtual lambda_impl* clone() const = 0;
		virtual lambda_impl* move() = 0;
		virtual string to_string() = 0;
		virtual string to_string(bool&) = 0;
		virtual void get_free_variables(set<variable>&, map<variable, int>&) = 0;
		virtual bool is_free_to_substitude(const variable&, set<variable>&, bool) = 0;
	};
	
	class lambda{
		friend string to_string(const lambda&, bool&);
		friend void get_free_variables(const lambda&, set<variable>&, map<variable, int>&);
		friend bool is_free_to_substitude(const lambda&, const variable&, set<variable>&, bool);
		friend ostream& operator<<(ostream& out, const lambda& l);
		lambda_impl* term;
	public:
		lambda(string);
		lambda(const char*);
		lambda(lambda_impl&);
		lambda(lambda_impl&&);
		lambda& operator=(const lambda_impl&);
		lambda& operator=(lambda_impl&&);
		lambda(const lambda&);
		lambda(lambda&&);
		lambda& operator=(const lambda&);
		lambda& operator=(lambda&&);
		virtual ~lambda();
		
		string to_string() const;
		operator string() const;
		
		bool is_application() const;
		bool is_abstraction() const;
		bool is_variable() const;
		
		bool is_free_to_substitude(const variable&, const lambda&) const;
		set<variable> get_free_variables() const;
	};
	
	string to_string(const lambda&, bool&);
	void get_free_variables(const lambda&, set<variable>&, map<variable, int>&);
	bool is_free_to_substitude(const lambda&, const variable&, set<variable>&, bool);
	ostream& operator<<(ostream&, const lambda&);
}

#endif // LAMBDA_HPP
