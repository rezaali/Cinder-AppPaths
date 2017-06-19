#include "Paths.h"
#include "Resources.h"

#include "cinder/app/App.h"

using namespace std;
using namespace ci;

namespace reza {
namespace paths {
bool createDirectory( const fs::path &path )
{
	if( !fs::exists( path ) ) {
		return fs::create_directory( path );
	}
	else {
		return true;
	}
}

bool createDirectories( const fs::path &path )
{
	if( !fs::exists( path ) ) {
		return fs::create_directories( path );
	}
	else {
		return true;
	}
}

fs::path addPath( const fs::path &prefix, const string &path, const string &seperator )
{
	fs::path result( prefix );
	if( path.length() > 0 ) {
		if( seperator.length() > 0 ) {
			result += seperator;
		}
		else {
			result += fs::path::preferred_separator;
		}
		result += fs::path( path );
	}
	return result;
}

fs::path getPath( const string &path )
{
	return addPath( ci::app::getAssetPath( ASSETS_PATH ), path );
}

fs::path getShadersPath( const string &path )
{
	return addPath( getPath( SHADERS_PATH ), path );
}

fs::path getSettingsPath( const string &path )
{
	return addPath( getPath( SETTINGS_PATH ), path );
}
} // namespace paths
} // namespace reza