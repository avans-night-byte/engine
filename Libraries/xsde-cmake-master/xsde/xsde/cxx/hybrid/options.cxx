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

#include <cxx/hybrid/options.hxx>

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
  namespace Hybrid
  {
    // options
    //

    options::
    options ()
    : generate_parser_ (),
      generate_serializer_ (),
      generate_aggregate_ (),
      suppress_validation_ (),
      suppress_parser_val_ (),
      suppress_serializer_val_ (),
      omit_default_attributes_ (),
      suppress_enum_ (),
      generate_clone_ (),
      generate_detach_ (),
      generate_insertion_ (),
      generate_extraction_ (),
      generate_forward_ (),
      generate_polymorphic_ (),
      runtime_polymorphic_ (),
      polymorphic_type_ (),
      generate_typeinfo_ (),
      polymorphic_schema_ (),
      reuse_style_mixin_ (),
      custom_data_ (),
      custom_type_ (),
      custom_parser_ (),
      custom_serializer_ (),
      root_element_first_ (),
      root_element_last_ (),
      root_element_all_ (),
      root_element_none_ (),
      root_element_ (),
      root_type_ (),
      pskel_type_suffix_ ("_pskel"),
      sskel_type_suffix_ ("_sskel"),
      pskel_file_suffix_ ("-pskel"),
      sskel_file_suffix_ ("-sskel"),
      pimpl_type_suffix_ ("_pimpl"),
      simpl_type_suffix_ ("_simpl"),
      pimpl_file_suffix_ ("-pimpl"),
      simpl_file_suffix_ ("-simpl"),
      paggr_type_suffix_ ("_paggr"),
      saggr_type_suffix_ ("_saggr"),
      hxx_regex_ (),
      ixx_regex_ (),
      cxx_regex_ (),
      hxx_prologue_file_ (),
      ixx_prologue_file_ (),
      cxx_prologue_file_ (),
      prologue_file_ (),
      hxx_epilogue_file_ (),
      ixx_epilogue_file_ (),
      cxx_epilogue_file_ (),
      epilogue_file_ ()
    {
    }

    options::
    options (int& argc,
             char** argv,
             bool erase,
             ::cli::unknown_mode opt,
             ::cli::unknown_mode arg)
    : generate_parser_ (),
      generate_serializer_ (),
      generate_aggregate_ (),
      suppress_validation_ (),
      suppress_parser_val_ (),
      suppress_serializer_val_ (),
      omit_default_attributes_ (),
      suppress_enum_ (),
      generate_clone_ (),
      generate_detach_ (),
      generate_insertion_ (),
      generate_extraction_ (),
      generate_forward_ (),
      generate_polymorphic_ (),
      runtime_polymorphic_ (),
      polymorphic_type_ (),
      generate_typeinfo_ (),
      polymorphic_schema_ (),
      reuse_style_mixin_ (),
      custom_data_ (),
      custom_type_ (),
      custom_parser_ (),
      custom_serializer_ (),
      root_element_first_ (),
      root_element_last_ (),
      root_element_all_ (),
      root_element_none_ (),
      root_element_ (),
      root_type_ (),
      pskel_type_suffix_ ("_pskel"),
      sskel_type_suffix_ ("_sskel"),
      pskel_file_suffix_ ("-pskel"),
      sskel_file_suffix_ ("-sskel"),
      pimpl_type_suffix_ ("_pimpl"),
      simpl_type_suffix_ ("_simpl"),
      pimpl_file_suffix_ ("-pimpl"),
      simpl_file_suffix_ ("-simpl"),
      paggr_type_suffix_ ("_paggr"),
      saggr_type_suffix_ ("_saggr"),
      hxx_regex_ (),
      ixx_regex_ (),
      cxx_regex_ (),
      hxx_prologue_file_ (),
      ixx_prologue_file_ (),
      cxx_prologue_file_ (),
      prologue_file_ (),
      hxx_epilogue_file_ (),
      ixx_epilogue_file_ (),
      cxx_epilogue_file_ (),
      epilogue_file_ ()
    {
      ::cli::argv_scanner s (argc, argv, erase);
      _parse (s, opt, arg);
    }

    options::
    options (int start,
             int& argc,
             char** argv,
             bool erase,
             ::cli::unknown_mode opt,
             ::cli::unknown_mode arg)
    : generate_parser_ (),
      generate_serializer_ (),
      generate_aggregate_ (),
      suppress_validation_ (),
      suppress_parser_val_ (),
      suppress_serializer_val_ (),
      omit_default_attributes_ (),
      suppress_enum_ (),
      generate_clone_ (),
      generate_detach_ (),
      generate_insertion_ (),
      generate_extraction_ (),
      generate_forward_ (),
      generate_polymorphic_ (),
      runtime_polymorphic_ (),
      polymorphic_type_ (),
      generate_typeinfo_ (),
      polymorphic_schema_ (),
      reuse_style_mixin_ (),
      custom_data_ (),
      custom_type_ (),
      custom_parser_ (),
      custom_serializer_ (),
      root_element_first_ (),
      root_element_last_ (),
      root_element_all_ (),
      root_element_none_ (),
      root_element_ (),
      root_type_ (),
      pskel_type_suffix_ ("_pskel"),
      sskel_type_suffix_ ("_sskel"),
      pskel_file_suffix_ ("-pskel"),
      sskel_file_suffix_ ("-sskel"),
      pimpl_type_suffix_ ("_pimpl"),
      simpl_type_suffix_ ("_simpl"),
      pimpl_file_suffix_ ("-pimpl"),
      simpl_file_suffix_ ("-simpl"),
      paggr_type_suffix_ ("_paggr"),
      saggr_type_suffix_ ("_saggr"),
      hxx_regex_ (),
      ixx_regex_ (),
      cxx_regex_ (),
      hxx_prologue_file_ (),
      ixx_prologue_file_ (),
      cxx_prologue_file_ (),
      prologue_file_ (),
      hxx_epilogue_file_ (),
      ixx_epilogue_file_ (),
      cxx_epilogue_file_ (),
      epilogue_file_ ()
    {
      ::cli::argv_scanner s (start, argc, argv, erase);
      _parse (s, opt, arg);
    }

    options::
    options (int& argc,
             char** argv,
             int& end,
             bool erase,
             ::cli::unknown_mode opt,
             ::cli::unknown_mode arg)
    : generate_parser_ (),
      generate_serializer_ (),
      generate_aggregate_ (),
      suppress_validation_ (),
      suppress_parser_val_ (),
      suppress_serializer_val_ (),
      omit_default_attributes_ (),
      suppress_enum_ (),
      generate_clone_ (),
      generate_detach_ (),
      generate_insertion_ (),
      generate_extraction_ (),
      generate_forward_ (),
      generate_polymorphic_ (),
      runtime_polymorphic_ (),
      polymorphic_type_ (),
      generate_typeinfo_ (),
      polymorphic_schema_ (),
      reuse_style_mixin_ (),
      custom_data_ (),
      custom_type_ (),
      custom_parser_ (),
      custom_serializer_ (),
      root_element_first_ (),
      root_element_last_ (),
      root_element_all_ (),
      root_element_none_ (),
      root_element_ (),
      root_type_ (),
      pskel_type_suffix_ ("_pskel"),
      sskel_type_suffix_ ("_sskel"),
      pskel_file_suffix_ ("-pskel"),
      sskel_file_suffix_ ("-sskel"),
      pimpl_type_suffix_ ("_pimpl"),
      simpl_type_suffix_ ("_simpl"),
      pimpl_file_suffix_ ("-pimpl"),
      simpl_file_suffix_ ("-simpl"),
      paggr_type_suffix_ ("_paggr"),
      saggr_type_suffix_ ("_saggr"),
      hxx_regex_ (),
      ixx_regex_ (),
      cxx_regex_ (),
      hxx_prologue_file_ (),
      ixx_prologue_file_ (),
      cxx_prologue_file_ (),
      prologue_file_ (),
      hxx_epilogue_file_ (),
      ixx_epilogue_file_ (),
      cxx_epilogue_file_ (),
      epilogue_file_ ()
    {
      ::cli::argv_scanner s (argc, argv, erase);
      _parse (s, opt, arg);
      end = s.end ();
    }

    options::
    options (int start,
             int& argc,
             char** argv,
             int& end,
             bool erase,
             ::cli::unknown_mode opt,
             ::cli::unknown_mode arg)
    : generate_parser_ (),
      generate_serializer_ (),
      generate_aggregate_ (),
      suppress_validation_ (),
      suppress_parser_val_ (),
      suppress_serializer_val_ (),
      omit_default_attributes_ (),
      suppress_enum_ (),
      generate_clone_ (),
      generate_detach_ (),
      generate_insertion_ (),
      generate_extraction_ (),
      generate_forward_ (),
      generate_polymorphic_ (),
      runtime_polymorphic_ (),
      polymorphic_type_ (),
      generate_typeinfo_ (),
      polymorphic_schema_ (),
      reuse_style_mixin_ (),
      custom_data_ (),
      custom_type_ (),
      custom_parser_ (),
      custom_serializer_ (),
      root_element_first_ (),
      root_element_last_ (),
      root_element_all_ (),
      root_element_none_ (),
      root_element_ (),
      root_type_ (),
      pskel_type_suffix_ ("_pskel"),
      sskel_type_suffix_ ("_sskel"),
      pskel_file_suffix_ ("-pskel"),
      sskel_file_suffix_ ("-sskel"),
      pimpl_type_suffix_ ("_pimpl"),
      simpl_type_suffix_ ("_simpl"),
      pimpl_file_suffix_ ("-pimpl"),
      simpl_file_suffix_ ("-simpl"),
      paggr_type_suffix_ ("_paggr"),
      saggr_type_suffix_ ("_saggr"),
      hxx_regex_ (),
      ixx_regex_ (),
      cxx_regex_ (),
      hxx_prologue_file_ (),
      ixx_prologue_file_ (),
      cxx_prologue_file_ (),
      prologue_file_ (),
      hxx_epilogue_file_ (),
      ixx_epilogue_file_ (),
      cxx_epilogue_file_ (),
      epilogue_file_ ()
    {
      ::cli::argv_scanner s (start, argc, argv, erase);
      _parse (s, opt, arg);
      end = s.end ();
    }

    options::
    options (::cli::scanner& s,
             ::cli::unknown_mode opt,
             ::cli::unknown_mode arg)
    : generate_parser_ (),
      generate_serializer_ (),
      generate_aggregate_ (),
      suppress_validation_ (),
      suppress_parser_val_ (),
      suppress_serializer_val_ (),
      omit_default_attributes_ (),
      suppress_enum_ (),
      generate_clone_ (),
      generate_detach_ (),
      generate_insertion_ (),
      generate_extraction_ (),
      generate_forward_ (),
      generate_polymorphic_ (),
      runtime_polymorphic_ (),
      polymorphic_type_ (),
      generate_typeinfo_ (),
      polymorphic_schema_ (),
      reuse_style_mixin_ (),
      custom_data_ (),
      custom_type_ (),
      custom_parser_ (),
      custom_serializer_ (),
      root_element_first_ (),
      root_element_last_ (),
      root_element_all_ (),
      root_element_none_ (),
      root_element_ (),
      root_type_ (),
      pskel_type_suffix_ ("_pskel"),
      sskel_type_suffix_ ("_sskel"),
      pskel_file_suffix_ ("-pskel"),
      sskel_file_suffix_ ("-sskel"),
      pimpl_type_suffix_ ("_pimpl"),
      simpl_type_suffix_ ("_simpl"),
      pimpl_file_suffix_ ("-pimpl"),
      simpl_file_suffix_ ("-simpl"),
      paggr_type_suffix_ ("_paggr"),
      saggr_type_suffix_ ("_saggr"),
      hxx_regex_ (),
      ixx_regex_ (),
      cxx_regex_ (),
      hxx_prologue_file_ (),
      ixx_prologue_file_ (),
      cxx_prologue_file_ (),
      prologue_file_ (),
      hxx_epilogue_file_ (),
      ixx_epilogue_file_ (),
      cxx_epilogue_file_ (),
      epilogue_file_ ()
    {
      _parse (s, opt, arg);
    }

    ::cli::usage_para options::
    print_usage (::std::wostream& os, ::cli::usage_para p)
    {
      CLI_POTENTIALLY_UNUSED (os);

      if (p == ::cli::usage_para::text)
        os << ::std::endl;

      os << "--generate-parser            Generate XML parsing code." << ::std::endl;

      os << "--generate-serializer        Generate XML serialization code." << ::std::endl;

      os << "--generate-aggregate         Generate parser/serializer aggregates for root" << ::std::endl
         << "                             elements and/or types." << ::std::endl;

      os << "--suppress-validation        Suppress the generation of validation code in" << ::std::endl
         << "                             parser and serializer." << ::std::endl;

      os << "--suppress-parser-val        Suppress the generation of validation code in" << ::std::endl
         << "                             parser." << ::std::endl;

      os << "--suppress-serializer-val    Suppress the generation of validation code in" << ::std::endl
         << "                             serializer." << ::std::endl;

      os << "--omit-default-attributes    Omit attributes with default and fixed values from" << ::std::endl
         << "                             serialized XML documents." << ::std::endl;

      os << "--suppress-enum              Suppress the generation of the XML Schema" << ::std::endl
         << "                             enumeration to C++ enum mapping." << ::std::endl;

      os << "--generate-clone             Generate clone functions for variable-length" << ::std::endl
         << "                             types." << ::std::endl;

      os << "--generate-detach            Generate detach functions for elements and" << ::std::endl
         << "                             attributes of variable-length types." << ::std::endl;

      os << "--generate-insertion <os>    Generate data representation stream insertion" << ::std::endl
         << "                             operators for the <os> output stream type." << ::std::endl;

      os << "--generate-extraction <is>   Generate data representation stream extraction" << ::std::endl
         << "                             operators for the <is> input stream type." << ::std::endl;

      os << "--generate-forward           Generate forward declaration file." << ::std::endl;

      os << "--generate-polymorphic       Generate polymorphism-aware code." << ::std::endl;

      os << "--runtime-polymorphic        Generate non-polymorphic code that uses the" << ::std::endl
         << "                             runtime library configured with polymorphism" << ::std::endl
         << "                             support." << ::std::endl;

      os << "--polymorphic-type <type>    Indicate that <type> is a root of a polymorphic" << ::std::endl
         << "                             type hierarchy." << ::std::endl;

      os << "--generate-typeinfo          Generate custom type information querying" << ::std::endl
         << "                             functions for polymorphic object model types." << ::std::endl;

      os << "--polymorphic-schema <file>  Indicate that <file> contains derivations of" << ::std::endl
         << "                             polymorphic types that are not otherwise visible" << ::std::endl
         << "                             from the schema being compiled." << ::std::endl;

      os << "--reuse-style-mixin          Generate code that supports the mixin base" << ::std::endl
         << "                             parser/serializer implementation reuse style." << ::std::endl;

      os << "--custom-data <type>         Add the ability to store custom data to the C++" << ::std::endl
         << "                             class generated for XML Schema type <type>." << ::std::endl;

      os << "--custom-type <map>          Use a custom type implementation instead of the" << ::std::endl
         << "                             generated version." << ::std::endl;

      os << "--custom-parser <map>        Use a custom parser implementation instead of the" << ::std::endl
         << "                             generated version." << ::std::endl;

      os << "--custom-serializer <map>    Use a custom serializer implementation instead of" << ::std::endl
         << "                             the generated version." << ::std::endl;

      os << "--root-element-first         Treat only the first global element as a document" << ::std::endl
         << "                             root." << ::std::endl;

      os << "--root-element-last          Treat only the last global element as a document" << ::std::endl
         << "                             root." << ::std::endl;

      os << "--root-element-all           Treat all global elements as document roots (the" << ::std::endl
         << "                             default behavior)." << ::std::endl;

      os << "--root-element-none          Do not treat any global elements as document" << ::std::endl
         << "                             roots." << ::std::endl;

      os << "--root-element <element>     Treat only <element> as a document root." << ::std::endl;

      os << "--root-type <type>           Generate parser/serializer aggregate for <type>." << ::std::endl;

      os << "--pskel-type-suffix <suffix> Use <suffix> instead of the default _pskel to" << ::std::endl
         << "                             construct the names of generated parser skeletons." << ::std::endl;

      os << "--sskel-type-suffix <suffix> Use <suffix> instead of the default _sskel to" << ::std::endl
         << "                             construct the names of generated serializer" << ::std::endl
         << "                             skeletons." << ::std::endl;

      os << "--pskel-file-suffix <suffix> Use <suffix> instead of the default -pskel to" << ::std::endl
         << "                             construct the names of generated parser skeleton" << ::std::endl
         << "                             files." << ::std::endl;

      os << "--sskel-file-suffix <suffix> Use <suffix> instead of the default -sskel to" << ::std::endl
         << "                             construct the names of generated serializer" << ::std::endl
         << "                             skeleton files." << ::std::endl;

      os << "--pimpl-type-suffix <suffix> Use <suffix> instead of the default _pimpl to" << ::std::endl
         << "                             construct the names of generated parser" << ::std::endl
         << "                             implementations." << ::std::endl;

      os << "--simpl-type-suffix <suffix> Use <suffix> instead of the default _simpl to" << ::std::endl
         << "                             construct the names of generated serializer" << ::std::endl
         << "                             implementations." << ::std::endl;

      os << "--pimpl-file-suffix <suffix> Use <suffix> instead of the default -pimpl to" << ::std::endl
         << "                             construct the names of generated parser" << ::std::endl
         << "                             implementation files." << ::std::endl;

      os << "--simpl-file-suffix <suffix> Use <suffix> instead of the default -simpl to" << ::std::endl
         << "                             construct the names of generated serializer" << ::std::endl
         << "                             implementation files." << ::std::endl;

      os << "--paggr-type-suffix <suffix> Use <suffix> instead of the default _paggr to" << ::std::endl
         << "                             construct the names of generated parser" << ::std::endl
         << "                             aggregates." << ::std::endl;

      os << "--saggr-type-suffix <suffix> Use <suffix> instead of the default _saggr to" << ::std::endl
         << "                             construct the names of generated serializer" << ::std::endl
         << "                             aggregates." << ::std::endl;

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
        _cli_options_map_["--generate-parser"] = 
        &::cli::thunk< options, bool, &options::generate_parser_ >;
        _cli_options_map_["--generate-serializer"] = 
        &::cli::thunk< options, bool, &options::generate_serializer_ >;
        _cli_options_map_["--generate-aggregate"] = 
        &::cli::thunk< options, bool, &options::generate_aggregate_ >;
        _cli_options_map_["--suppress-validation"] = 
        &::cli::thunk< options, bool, &options::suppress_validation_ >;
        _cli_options_map_["--suppress-parser-val"] = 
        &::cli::thunk< options, bool, &options::suppress_parser_val_ >;
        _cli_options_map_["--suppress-serializer-val"] = 
        &::cli::thunk< options, bool, &options::suppress_serializer_val_ >;
        _cli_options_map_["--omit-default-attributes"] = 
        &::cli::thunk< options, bool, &options::omit_default_attributes_ >;
        _cli_options_map_["--suppress-enum"] = 
        &::cli::thunk< options, bool, &options::suppress_enum_ >;
        _cli_options_map_["--generate-clone"] = 
        &::cli::thunk< options, bool, &options::generate_clone_ >;
        _cli_options_map_["--generate-detach"] = 
        &::cli::thunk< options, bool, &options::generate_detach_ >;
        _cli_options_map_["--generate-insertion"] = 
        &::cli::thunk< options, NarrowStrings, &options::generate_insertion_ >;
        _cli_options_map_["--generate-extraction"] = 
        &::cli::thunk< options, NarrowStrings, &options::generate_extraction_ >;
        _cli_options_map_["--generate-forward"] = 
        &::cli::thunk< options, bool, &options::generate_forward_ >;
        _cli_options_map_["--generate-polymorphic"] = 
        &::cli::thunk< options, bool, &options::generate_polymorphic_ >;
        _cli_options_map_["--runtime-polymorphic"] = 
        &::cli::thunk< options, bool, &options::runtime_polymorphic_ >;
        _cli_options_map_["--polymorphic-type"] = 
        &::cli::thunk< options, NarrowStrings, &options::polymorphic_type_ >;
        _cli_options_map_["--generate-typeinfo"] = 
        &::cli::thunk< options, bool, &options::generate_typeinfo_ >;
        _cli_options_map_["--polymorphic-schema"] = 
        &::cli::thunk< options, NarrowStrings, &options::polymorphic_schema_ >;
        _cli_options_map_["--reuse-style-mixin"] = 
        &::cli::thunk< options, bool, &options::reuse_style_mixin_ >;
        _cli_options_map_["--custom-data"] = 
        &::cli::thunk< options, NarrowStrings, &options::custom_data_ >;
        _cli_options_map_["--custom-type"] = 
        &::cli::thunk< options, NarrowStrings, &options::custom_type_ >;
        _cli_options_map_["--custom-parser"] = 
        &::cli::thunk< options, NarrowStrings, &options::custom_parser_ >;
        _cli_options_map_["--custom-serializer"] = 
        &::cli::thunk< options, NarrowStrings, &options::custom_serializer_ >;
        _cli_options_map_["--root-element-first"] = 
        &::cli::thunk< options, bool, &options::root_element_first_ >;
        _cli_options_map_["--root-element-last"] = 
        &::cli::thunk< options, bool, &options::root_element_last_ >;
        _cli_options_map_["--root-element-all"] = 
        &::cli::thunk< options, bool, &options::root_element_all_ >;
        _cli_options_map_["--root-element-none"] = 
        &::cli::thunk< options, bool, &options::root_element_none_ >;
        _cli_options_map_["--root-element"] = 
        &::cli::thunk< options, NarrowStrings, &options::root_element_ >;
        _cli_options_map_["--root-type"] = 
        &::cli::thunk< options, NarrowStrings, &options::root_type_ >;
        _cli_options_map_["--pskel-type-suffix"] = 
        &::cli::thunk< options, NarrowString, &options::pskel_type_suffix_ >;
        _cli_options_map_["--sskel-type-suffix"] = 
        &::cli::thunk< options, NarrowString, &options::sskel_type_suffix_ >;
        _cli_options_map_["--pskel-file-suffix"] = 
        &::cli::thunk< options, NarrowString, &options::pskel_file_suffix_ >;
        _cli_options_map_["--sskel-file-suffix"] = 
        &::cli::thunk< options, NarrowString, &options::sskel_file_suffix_ >;
        _cli_options_map_["--pimpl-type-suffix"] = 
        &::cli::thunk< options, NarrowString, &options::pimpl_type_suffix_ >;
        _cli_options_map_["--simpl-type-suffix"] = 
        &::cli::thunk< options, NarrowString, &options::simpl_type_suffix_ >;
        _cli_options_map_["--pimpl-file-suffix"] = 
        &::cli::thunk< options, NarrowString, &options::pimpl_file_suffix_ >;
        _cli_options_map_["--simpl-file-suffix"] = 
        &::cli::thunk< options, NarrowString, &options::simpl_file_suffix_ >;
        _cli_options_map_["--paggr-type-suffix"] = 
        &::cli::thunk< options, NarrowString, &options::paggr_type_suffix_ >;
        _cli_options_map_["--saggr-type-suffix"] = 
        &::cli::thunk< options, NarrowString, &options::saggr_type_suffix_ >;
        _cli_options_map_["--hxx-regex"] = 
        &::cli::thunk< options, NarrowStrings, &options::hxx_regex_ >;
        _cli_options_map_["--ixx-regex"] = 
        &::cli::thunk< options, NarrowStrings, &options::ixx_regex_ >;
        _cli_options_map_["--cxx-regex"] = 
        &::cli::thunk< options, NarrowStrings, &options::cxx_regex_ >;
        _cli_options_map_["--hxx-prologue-file"] = 
        &::cli::thunk< options, NarrowStrings, &options::hxx_prologue_file_ >;
        _cli_options_map_["--ixx-prologue-file"] = 
        &::cli::thunk< options, NarrowStrings, &options::ixx_prologue_file_ >;
        _cli_options_map_["--cxx-prologue-file"] = 
        &::cli::thunk< options, NarrowStrings, &options::cxx_prologue_file_ >;
        _cli_options_map_["--prologue-file"] = 
        &::cli::thunk< options, NarrowStrings, &options::prologue_file_ >;
        _cli_options_map_["--hxx-epilogue-file"] = 
        &::cli::thunk< options, NarrowStrings, &options::hxx_epilogue_file_ >;
        _cli_options_map_["--ixx-epilogue-file"] = 
        &::cli::thunk< options, NarrowStrings, &options::ixx_epilogue_file_ >;
        _cli_options_map_["--cxx-epilogue-file"] = 
        &::cli::thunk< options, NarrowStrings, &options::cxx_epilogue_file_ >;
        _cli_options_map_["--epilogue-file"] = 
        &::cli::thunk< options, NarrowStrings, &options::epilogue_file_ >;
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
      if (::CXX::options::_parse (o, s))
        return true;

      return false;
    }

    bool options::
    _parse (::cli::scanner& s,
            ::cli::unknown_mode opt_mode,
            ::cli::unknown_mode arg_mode)
    {
      // Can't skip combined flags (--no-combined-flags).
      //
      assert (opt_mode != ::cli::unknown_mode::skip);

      bool r = false;
      bool opt = true;

      while (s.more ())
      {
        const char* o = s.peek ();

        if (std::strcmp (o, "--") == 0)
        {
          opt = false;
          s.skip ();
          r = true;
          continue;
        }

        if (opt)
        {
          if (_parse (o, s))
          {
            r = true;
            continue;
          }

          if (std::strncmp (o, "-", 1) == 0 && o[1] != '\0')
          {
            // Handle combined option values.
            //
            std::string co;
            if (const char* v = std::strchr (o, '='))
            {
              co.assign (o, 0, v - o);
              ++v;

              int ac (2);
              char* av[] =
              {
                const_cast<char*> (co.c_str ()),
                const_cast<char*> (v)
              };

              ::cli::argv_scanner ns (0, ac, av);

              if (_parse (co.c_str (), ns))
              {
                // Parsed the option but not its value?
                //
                if (ns.end () != 2)
                  throw ::cli::invalid_value (co, v);

                s.next ();
                r = true;
                continue;
              }
              else
              {
                // Set the unknown option and fall through.
                //
                o = co.c_str ();
              }
            }

            // Handle combined flags.
            //
            char cf[3];
            {
              const char* p = o + 1;
              for (; *p != '\0'; ++p)
              {
                if (!((*p >= 'a' && *p <= 'z') ||
                      (*p >= 'A' && *p <= 'Z') ||
                      (*p >= '0' && *p <= '9')))
                  break;
              }

              if (*p == '\0')
              {
                for (p = o + 1; *p != '\0'; ++p)
                {
                  std::strcpy (cf, "-");
                  cf[1] = *p;
                  cf[2] = '\0';

                  int ac (1);
                  char* av[] = 
                  {
                    cf
                  };

                  ::cli::argv_scanner ns (0, ac, av);

                  if (!_parse (cf, ns))
                    break;
                }

                if (*p == '\0')
                {
                  // All handled.
                  //
                  s.next ();
                  r = true;
                  continue;
                }
                else
                {
                  // Set the unknown option and fall through.
                  //
                  o = cf;
                }
              }
            }

            switch (opt_mode)
            {
              case ::cli::unknown_mode::skip:
              {
                s.skip ();
                r = true;
                continue;
              }
              case ::cli::unknown_mode::stop:
              {
                break;
              }
              case ::cli::unknown_mode::fail:
              {
                throw ::cli::unknown_option (o);
              }
            }

            break;
          }
        }

        switch (arg_mode)
        {
          case ::cli::unknown_mode::skip:
          {
            s.skip ();
            r = true;
            continue;
          }
          case ::cli::unknown_mode::stop:
          {
            break;
          }
          case ::cli::unknown_mode::fail:
          {
            throw ::cli::unknown_argument (o);
          }
        }

        break;
      }

      return r;
    }
  }
}

// Begin epilogue.
//
//
// End epilogue.

