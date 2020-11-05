// -*- C++ -*-
//
// This file was generated by CLI, a command line interface
// compiler for C++.
//

// Begin prologue.
//
#include <options-parser.hxx>
//
// End prologue.

#include <cxx/options.hxx>

#include <map>
#include <set>
#include <string>
#include <vector>
#include <ostream>
#include <sstream>

namespace cli
{
  template <typename X>
  struct parser
  {
    static void
    parse (X& x, scanner& s)
    {
      using namespace std;

      const char* o (s.next ());

      if (s.more ())
      {
        string v (s.next ());
        istringstream is (v);
        if (!(is >> x && is.peek () == istringstream::traits_type::eof ()))
          throw invalid_value (o, v);
      }
      else
        throw missing_value (o);
    }
  };

  template <>
  struct parser<bool>
  {
    static void
    parse (bool& x, scanner& s)
    {
      s.next ();
      x = true;
    }
  };

  template <>
  struct parser<std::string>
  {
    static void
    parse (std::string& x, scanner& s)
    {
      const char* o (s.next ());

      if (s.more ())
        x = s.next ();
      else
        throw missing_value (o);
    }
  };

  template <typename X>
  struct parser<std::vector<X> >
  {
    static void
    parse (std::vector<X>& c, scanner& s)
    {
      X x;
      parser<X>::parse (x, s);
      c.push_back (x);
    }
  };

  template <typename X>
  struct parser<std::set<X> >
  {
    static void
    parse (std::set<X>& c, scanner& s)
    {
      X x;
      parser<X>::parse (x, s);
      c.insert (x);
    }
  };

  template <typename K, typename V>
  struct parser<std::map<K, V> >
  {
    static void
    parse (std::map<K, V>& m, scanner& s)
    {
      const char* o (s.next ());

      if (s.more ())
      {
        std::string ov (s.next ());
        std::string::size_type p = ov.find ('=');

        K k = K ();
        V v = V ();
        std::string kstr (ov, 0, p);
        std::string vstr (ov, (p != std::string::npos ? p + 1 : ov.size ()));

        int ac (2);
        char* av[] = 
        {
          const_cast<char*> (o), 0
        };

        if (!kstr.empty ())
        {
          av[1] = const_cast<char*> (kstr.c_str ());
          argv_scanner s (0, ac, av);
          parser<K>::parse (k, s);
        }

        if (!vstr.empty ())
        {
          av[1] = const_cast<char*> (vstr.c_str ());
          argv_scanner s (0, ac, av);
          parser<V>::parse (v, s);
        }

        m[k] = v;
      }
      else
        throw missing_value (o);
    }
  };

  template <typename X, typename T, T X::*M>
  void
  thunk (X& x, scanner& s)
  {
    parser<T>::parse (x.*M, s);
  }
}

#include <map>
#include <cstring>

namespace CXX
{
  // options
  //

  options::
  options ()
  : output_dir_ (),
    char_encoding_ ("utf8"),
    no_stl_ (),
    no_iostream_ (),
    no_exceptions_ (),
    no_long_long_ (),
    custom_allocator_ (),
    generate_inline_ (),
    suppress_reset_ (),
    generate_xml_schema_ (),
    extern_xml_schema_ (),
    namespace_map_ (),
    namespace_regex_ (),
    namespace_regex_trace_ (),
    reserved_name_ (),
    include_with_brackets_ (),
    include_prefix_ (),
    include_regex_ (),
    include_regex_trace_ (),
    guard_prefix_ (),
    hxx_suffix_ (".hxx"),
    ixx_suffix_ (".ixx"),
    cxx_suffix_ (".cxx"),
    fwd_suffix_ ("-fwd.hxx"),
    hxx_regex_ (),
    ixx_regex_ (),
    cxx_regex_ (),
    fwd_regex_ (),
    hxx_prologue_ (),
    ixx_prologue_ (),
    cxx_prologue_ (),
    fwd_prologue_ (),
    prologue_ (),
    hxx_epilogue_ (),
    ixx_epilogue_ (),
    cxx_epilogue_ (),
    fwd_epilogue_ (),
    epilogue_ (),
    hxx_prologue_file_ (),
    ixx_prologue_file_ (),
    cxx_prologue_file_ (),
    fwd_prologue_file_ (),
    prologue_file_ (),
    hxx_epilogue_file_ (),
    ixx_epilogue_file_ (),
    cxx_epilogue_file_ (),
    fwd_epilogue_file_ (),
    epilogue_file_ ()
  {
  }

  ::cli::usage_para options::
  print_usage (::std::wostream& os, ::cli::usage_para p)
  {
    CLI_POTENTIALLY_UNUSED (os);

    if (p == ::cli::usage_para::text)
      os << ::std::endl;

    os << "--output-dir <dir>           Write generated files to <dir> instead of the" << ::std::endl
       << "                             current directory." << ::std::endl;

    os << "--char-encoding <enc>        Specify the application character encoding." << ::std::endl;

    os << "--no-stl                     Generate code that does not use the C++ Standard" << ::std::endl
       << "                             Template Library (STL)." << ::std::endl;

    os << "--no-iostream                Generate code that does not use the C++ standard" << ::std::endl
       << "                             input/output stream library (iostream)." << ::std::endl;

    os << "--no-exceptions              Generate code that does not use C++ exceptions." << ::std::endl;

    os << "--no-long-long               Generate code that does not use the long long and" << ::std::endl
       << "                             unsigned long long types." << ::std::endl;

    os << "--custom-allocator           Generate code that performs memory management" << ::std::endl
       << "                             using custom allocator functions provided by your" << ::std::endl
       << "                             application instead of the standard operator new" << ::std::endl
       << "                             and delete." << ::std::endl;

    os << "--generate-inline            Generate simple functions inline." << ::std::endl;

    os << "--suppress-reset             Suppress the generation of parser/serializer reset" << ::std::endl
       << "                             code." << ::std::endl;

    os << "--generate-xml-schema        Generate a C++ header files as if the schema being" << ::std::endl
       << "                             compiled defines the XML Schema namespace." << ::std::endl;

    os << "--extern-xml-schema <file>   Include a header file derived from <file> instead" << ::std::endl
       << "                             of generating the XML Schema namespace mapping" << ::std::endl
       << "                             inline." << ::std::endl;

    os << "--namespace-map <xns>=<cns>  Map XML Schema namespace <xns> to C++ namespace" << ::std::endl
       << "                             <cns>." << ::std::endl;

    os << "--namespace-regex <regex>    Add <regex> to the list of regular expressions" << ::std::endl
       << "                             used to translate XML Schema namespace names to" << ::std::endl
       << "                             C++ namespace names." << ::std::endl;

    os << "--namespace-regex-trace      Trace the process of applying regular expressions" << ::std::endl
       << "                             specified with the --namespace-regex option." << ::std::endl;

    os << "--reserved-name <n>[=<r>]    Add name <n> to the list of names that should not" << ::std::endl
       << "                             be used as identifiers." << ::std::endl;

    os << "--include-with-brackets      Use angle brackets (<>) instead of quotes (\"\") in" << ::std::endl
       << "                             generated #include directives." << ::std::endl;

    os << "--include-prefix <prefix>    Add <prefix> to generated #include directive" << ::std::endl
       << "                             paths." << ::std::endl;

    os << "--include-regex <regex>      Add <regex> to the list of regular expressions" << ::std::endl
       << "                             used to transform #include directive paths." << ::std::endl;

    os << "--include-regex-trace        Trace the process of applying regular expressions" << ::std::endl
       << "                             specified with the --include-regex option." << ::std::endl;

    os << "--guard-prefix <prefix>      Add <prefix> to generated header inclusion guards." << ::std::endl;

    os << "--hxx-suffix <suffix>        Use the provided <suffix> instead of the default" << ::std::endl
       << "                             .hxx to construct the name of the header file." << ::std::endl;

    os << "--ixx-suffix <suffix>        Use the provided <suffix> instead of the default" << ::std::endl
       << "                             .ixx to construct the name of the inline file." << ::std::endl;

    os << "--cxx-suffix <suffix>        Use the provided <suffix> instead of the default" << ::std::endl
       << "                             .cxx to construct the name of the source file." << ::std::endl;

    os << "--fwd-suffix <suffix>        Use the provided <suffix> instead of the default" << ::std::endl
       << "                             -fwd.hxx to construct the name of the forward" << ::std::endl
       << "                             declaration file." << ::std::endl;

    os << "--hxx-regex <regex>          Use the provided expression to construct the name" << ::std::endl
       << "                             of the header file." << ::std::endl;

    os << "--ixx-regex <regex>          Use the provided expression to construct the name" << ::std::endl
       << "                             of the inline file." << ::std::endl;

    os << "--cxx-regex <regex>          Use the provided expression to construct the name" << ::std::endl
       << "                             of the source file." << ::std::endl;

    os << "--fwd-regex <regex>          Use the provided expression to construct the name" << ::std::endl
       << "                             of the forward declaration file." << ::std::endl;

    os << "--hxx-prologue <text>        Insert <text> at the beginning of the header file." << ::std::endl;

    os << "--ixx-prologue <text>        Insert <text> at the beginning of the inline file." << ::std::endl;

    os << "--cxx-prologue <text>        Insert <text> at the beginning of the source file." << ::std::endl;

    os << "--fwd-prologue <text>        Insert <text> at the beginning of the forward" << ::std::endl
       << "                             declaration file." << ::std::endl;

    os << "--prologue <text>            Insert <text> at the beginning of each generated" << ::std::endl
       << "                             file for which there is no file-specific prologue." << ::std::endl;

    os << "--hxx-epilogue <text>        Insert <text> at the end of the header file." << ::std::endl;

    os << "--ixx-epilogue <text>        Insert <text> at the end of the inline file." << ::std::endl;

    os << "--cxx-epilogue <text>        Insert <text> at the end of the source file." << ::std::endl;

    os << "--fwd-epilogue <text>        Insert <text> at the end of the forward" << ::std::endl
       << "                             declaration file." << ::std::endl;

    os << "--epilogue <text>            Insert <text> at the end of each generated file" << ::std::endl
       << "                             for which there is no file-specific epilogue." << ::std::endl;

    os << "--hxx-prologue-file <file>   Insert the content of the <file> at the beginning" << ::std::endl
       << "                             of the header file." << ::std::endl;

    os << "--ixx-prologue-file <file>   Insert the content of the <file> at the beginning" << ::std::endl
       << "                             of the inline file." << ::std::endl;

    os << "--cxx-prologue-file <file>   Insert the content of the <file> at the beginning" << ::std::endl
       << "                             of the source file." << ::std::endl;

    os << "--fwd-prologue-file <file>   Insert the content of the <file> at the beginning" << ::std::endl
       << "                             of the forward declaration file." << ::std::endl;

    os << "--prologue-file <file>       Insert the content of the <file> at the beginning" << ::std::endl
       << "                             of each generated file for which there is no" << ::std::endl
       << "                             file-specific prologue file." << ::std::endl;

    os << "--hxx-epilogue-file <file>   Insert the content of the <file> at the end of the" << ::std::endl
       << "                             header file." << ::std::endl;

    os << "--ixx-epilogue-file <file>   Insert the content of the <file> at the end of the" << ::std::endl
       << "                             inline file." << ::std::endl;

    os << "--cxx-epilogue-file <file>   Insert the content of the <file> at the end of the" << ::std::endl
       << "                             source file." << ::std::endl;

    os << "--fwd-epilogue-file <file>   Insert the content of the <file> at the end of the" << ::std::endl
       << "                             forward declaration file." << ::std::endl;

    os << "--epilogue-file <file>       Insert the content of the <file> at the end of" << ::std::endl
       << "                             each generated file for which there is no" << ::std::endl
       << "                             file-specific epilogue file." << ::std::endl;

    p = ::cli::usage_para::option;

    return p;
  }

  typedef
  std::map<std::string, void (*) (options&, ::cli::scanner&)>
  _cli_options_map;

  static _cli_options_map _cli_options_map_;

  struct _cli_options_map_init
  {
    _cli_options_map_init ()
    {
      _cli_options_map_["--output-dir"] = 
      &::cli::thunk< options, NarrowString, &options::output_dir_ >;
      _cli_options_map_["--char-encoding"] = 
      &::cli::thunk< options, NarrowString, &options::char_encoding_ >;
      _cli_options_map_["--no-stl"] = 
      &::cli::thunk< options, bool, &options::no_stl_ >;
      _cli_options_map_["--no-iostream"] = 
      &::cli::thunk< options, bool, &options::no_iostream_ >;
      _cli_options_map_["--no-exceptions"] = 
      &::cli::thunk< options, bool, &options::no_exceptions_ >;
      _cli_options_map_["--no-long-long"] = 
      &::cli::thunk< options, bool, &options::no_long_long_ >;
      _cli_options_map_["--custom-allocator"] = 
      &::cli::thunk< options, bool, &options::custom_allocator_ >;
      _cli_options_map_["--generate-inline"] = 
      &::cli::thunk< options, bool, &options::generate_inline_ >;
      _cli_options_map_["--suppress-reset"] = 
      &::cli::thunk< options, bool, &options::suppress_reset_ >;
      _cli_options_map_["--generate-xml-schema"] = 
      &::cli::thunk< options, bool, &options::generate_xml_schema_ >;
      _cli_options_map_["--extern-xml-schema"] = 
      &::cli::thunk< options, NarrowString, &options::extern_xml_schema_ >;
      _cli_options_map_["--namespace-map"] = 
      &::cli::thunk< options, NarrowStrings, &options::namespace_map_ >;
      _cli_options_map_["--namespace-regex"] = 
      &::cli::thunk< options, NarrowStrings, &options::namespace_regex_ >;
      _cli_options_map_["--namespace-regex-trace"] = 
      &::cli::thunk< options, bool, &options::namespace_regex_trace_ >;
      _cli_options_map_["--reserved-name"] = 
      &::cli::thunk< options, NarrowStrings, &options::reserved_name_ >;
      _cli_options_map_["--include-with-brackets"] = 
      &::cli::thunk< options, bool, &options::include_with_brackets_ >;
      _cli_options_map_["--include-prefix"] = 
      &::cli::thunk< options, NarrowString, &options::include_prefix_ >;
      _cli_options_map_["--include-regex"] = 
      &::cli::thunk< options, NarrowStrings, &options::include_regex_ >;
      _cli_options_map_["--include-regex-trace"] = 
      &::cli::thunk< options, bool, &options::include_regex_trace_ >;
      _cli_options_map_["--guard-prefix"] = 
      &::cli::thunk< options, NarrowString, &options::guard_prefix_ >;
      _cli_options_map_["--hxx-suffix"] = 
      &::cli::thunk< options, NarrowString, &options::hxx_suffix_ >;
      _cli_options_map_["--ixx-suffix"] = 
      &::cli::thunk< options, NarrowString, &options::ixx_suffix_ >;
      _cli_options_map_["--cxx-suffix"] = 
      &::cli::thunk< options, NarrowString, &options::cxx_suffix_ >;
      _cli_options_map_["--fwd-suffix"] = 
      &::cli::thunk< options, NarrowString, &options::fwd_suffix_ >;
      _cli_options_map_["--hxx-regex"] = 
      &::cli::thunk< options, NarrowString, &options::hxx_regex_ >;
      _cli_options_map_["--ixx-regex"] = 
      &::cli::thunk< options, NarrowString, &options::ixx_regex_ >;
      _cli_options_map_["--cxx-regex"] = 
      &::cli::thunk< options, NarrowString, &options::cxx_regex_ >;
      _cli_options_map_["--fwd-regex"] = 
      &::cli::thunk< options, NarrowString, &options::fwd_regex_ >;
      _cli_options_map_["--hxx-prologue"] = 
      &::cli::thunk< options, NarrowStrings, &options::hxx_prologue_ >;
      _cli_options_map_["--ixx-prologue"] = 
      &::cli::thunk< options, NarrowStrings, &options::ixx_prologue_ >;
      _cli_options_map_["--cxx-prologue"] = 
      &::cli::thunk< options, NarrowStrings, &options::cxx_prologue_ >;
      _cli_options_map_["--fwd-prologue"] = 
      &::cli::thunk< options, NarrowStrings, &options::fwd_prologue_ >;
      _cli_options_map_["--prologue"] = 
      &::cli::thunk< options, NarrowStrings, &options::prologue_ >;
      _cli_options_map_["--hxx-epilogue"] = 
      &::cli::thunk< options, NarrowStrings, &options::hxx_epilogue_ >;
      _cli_options_map_["--ixx-epilogue"] = 
      &::cli::thunk< options, NarrowStrings, &options::ixx_epilogue_ >;
      _cli_options_map_["--cxx-epilogue"] = 
      &::cli::thunk< options, NarrowStrings, &options::cxx_epilogue_ >;
      _cli_options_map_["--fwd-epilogue"] = 
      &::cli::thunk< options, NarrowStrings, &options::fwd_epilogue_ >;
      _cli_options_map_["--epilogue"] = 
      &::cli::thunk< options, NarrowStrings, &options::epilogue_ >;
      _cli_options_map_["--hxx-prologue-file"] = 
      &::cli::thunk< options, NarrowString, &options::hxx_prologue_file_ >;
      _cli_options_map_["--ixx-prologue-file"] = 
      &::cli::thunk< options, NarrowString, &options::ixx_prologue_file_ >;
      _cli_options_map_["--cxx-prologue-file"] = 
      &::cli::thunk< options, NarrowString, &options::cxx_prologue_file_ >;
      _cli_options_map_["--fwd-prologue-file"] = 
      &::cli::thunk< options, NarrowString, &options::fwd_prologue_file_ >;
      _cli_options_map_["--prologue-file"] = 
      &::cli::thunk< options, NarrowString, &options::prologue_file_ >;
      _cli_options_map_["--hxx-epilogue-file"] = 
      &::cli::thunk< options, NarrowString, &options::hxx_epilogue_file_ >;
      _cli_options_map_["--ixx-epilogue-file"] = 
      &::cli::thunk< options, NarrowString, &options::ixx_epilogue_file_ >;
      _cli_options_map_["--cxx-epilogue-file"] = 
      &::cli::thunk< options, NarrowString, &options::cxx_epilogue_file_ >;
      _cli_options_map_["--fwd-epilogue-file"] = 
      &::cli::thunk< options, NarrowString, &options::fwd_epilogue_file_ >;
      _cli_options_map_["--epilogue-file"] = 
      &::cli::thunk< options, NarrowString, &options::epilogue_file_ >;
    }
  };

  static _cli_options_map_init _cli_options_map_init_;

  bool options::
  _parse (const char* o, ::cli::scanner& s)
  {
    _cli_options_map::const_iterator i (_cli_options_map_.find (o));

    if (i != _cli_options_map_.end ())
    {
      (*(i->second)) (*this, s);
      return true;
    }

    // options base
    //
    if (::options::_parse (o, s))
      return true;

    return false;
  }
}

// Begin epilogue.
//
//
// End epilogue.

