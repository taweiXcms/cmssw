#ifndef Utilities_CondDBTools_h
#define Utilities_CondDBTools_h

#include "CondCore/CondDB/interface/Time.h"
#include "CondCore/DBCommon/interface/DbSession.h"
//
#include <string>

namespace cond {

  namespace persistency {

    class Session;

    typedef enum { NEW=0, UPDATE, REPLACE } UpdatePolicy;

    size_t copyTag( const std::string& sourceTag, 
		    Session& sourceSession, 
		    const std::string& destTag, 
		    Session& destSession, 
		    UpdatePolicy policy,
		    bool log ); 
  

    size_t importIovs( const std::string& sourceTag, 
		       Session& sourceSession, 
		       const std::string& destTag, 
		       Session& destSession, 
		       cond::Time_t begin,
		       cond::Time_t end,
		       const std::string& description,
		       bool log );  

    bool copyIov( Session& session,
		  const std::string& sourceTag,
		  const std::string& destTag,
		  cond::Time_t souceSince,
		  cond::Time_t destSince,
		  const std::string& description,
		  bool log );
 
 }

}

#endif
