

#ifndef t323gpmsg_h
#define t323gpmsg_h

#include "tipcmsg.h"

//------------------------------------------------------------------

//  Forward declarations
namespace tipc
{
class Server;
}

//------------------------------------------------------------------

using namespace tipc;

namespace _3gp_io
{

void addParsers(tipc::Server *srv);

//************************************************************************************
//    Write messages
//************************************************************************************

class InitLW3gpParser : public tipc::MessageParser
{
	//Syntax: $initLW3gp <id> <fp> <props fp>
	//Reply: ok | err

public:
	QString header() const { return "$initLW3gp"; }
	void operator()(Message &stream);
};

//------------------------------------------------------------------------------

class LWSetFrameRateParser : public tipc::MessageParser
{
	//Syntax: $LW3gpSetFrameRate <id> <fps>
	//Reply: ok | err

public:
	QString header() const { return "$LW3gpSetFrameRate"; }
	void operator()(Message &stream);
};

//------------------------------------------------------------------------------

class LWImageWriteParser : public tipc::MessageParser
{
	//Syntax: [$LW3gpImageWrite <id> <frameIdx> <lx> <ly>] [data writer]
	//Reply: ok | err

public:
	QString header() const { return "$LW3gpImageWrite"; }
	void operator()(Message &stream);
};

//------------------------------------------------------------------------------

class LWSaveSoundTrackParser : public tipc::MessageParser
{
	//Syntax: $LW3gpSaveSoundTrack <id> <sampleRate> <bps> <chanCount> <sCount> <signedSample> <shmem-id>
	//Reply: ok | err

public:
	QString header() const { return "$LW3gpSaveSoundTrack"; }
	void operator()(Message &stream);
};

//------------------------------------------------------------------------------

class CloseLW3gpParser : public tipc::MessageParser
{
	//Syntax: $closeLW3gp <id>
	//Reply: ok | err

public:
	QString header() const { return "$closeLW3gp"; }
	void operator()(Message &stream);
};

//************************************************************************************
//    Read messages
//************************************************************************************

class InitLR3gpParser : public tipc::MessageParser
{
	//Syntax: $initLR3gp <id> <fp>
	//Reply: ok <lx> <ly> <framerate> | err

public:
	QString header() const { return "$initLR3gp"; }
	void operator()(Message &stream);
};

//------------------------------------------------------------------------------

class LRLoadInfoParser : public tipc::MessageParser
{
	//Syntax: $LR3gpLoadInfo <id> <shmem id>
	//Reply: ok <frameCount> | err

	//NOTE: Expects an external call to $shmem_release <shmem_id> after data is dealt with.

public:
	QString header() const { return "$LR3gpLoadInfo"; }
	void operator()(Message &stream);
};

//------------------------------------------------------------------------------

class LREnableRandomAccessReadParser : public tipc::MessageParser
{
	//Syntax: $LR3gpEnableRandomAccessRead <id> <"true" | "false">
	//Reply: ok | err

public:
	QString header() const { return "$LR3gpEnableRandomAccessRead"; }
	void operator()(Message &stream);
};

//------------------------------------------------------------------------------

class LRImageReadParser : public tipc::MessageParser
{
	//Syntax: $LR3gpImageRead <id> <lx> <ly> <bypp> <frameIdx> <x> <y> <shrinkX> <shrinkY>
	//Reply: [data reader]

public:
	QString header() const { return "$LR3gpImageRead"; }
	void operator()(Message &stream);
};

//------------------------------------------------------------------------------

class CloseLR3gpParser : public tipc::MessageParser
{
	//Syntax: $closeLR3gp <id>
	//Reply: ok | err

public:
	QString header() const { return "$closeLR3gp"; }
	void operator()(Message &stream);
};

} //namespace _3gp_io

#endif //t323gpmsg_h
