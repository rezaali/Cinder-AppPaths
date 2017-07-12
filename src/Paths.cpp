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

void copyDirectory( const fs::path &fromPath, const fs::path &toPath )
{
	map<fs::path, fs::path> directories;
	directories[fs::path( "" )] = fromPath;

	fs::recursive_directory_iterator it( fromPath ), eit;
	for( ; it != eit; ++it ) {
		fs::path pth = it->path();
		if( fs::is_directory( pth ) ) {
			directories[pth.filename()] = pth;
		}
	}

	fs::path folder = toPath;
	createDirectory( folder );

	for( auto &it : directories ) {
		fs::path dir = folder;
		if( !it.first.empty() ) {
			dir += "/";
			dir += it.first;
			createDirectory( dir );
		}

		fs::directory_iterator dit( it.second ), deit;
		for( ; dit != deit; ++dit ) {
			fs::path from = dit->path();
			if( !fs::is_directory( from ) ) {
				if( from.extension() != ".DS_Store" ) {
					fs::path to = dir;
					to += "/";
					to += from.filename();
					if( fs::exists( to ) ) {
						fs::remove( to );
					}
					fs::copy( from, to );
				}
			}
		}
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

fs::path getResourcesPath( const string &path )
{
	return addPath( ci::app::Platform::get()->getResourceDirectory(), path );
}

fs::path getResourcesAssetsPath( const string &path )
{
	return addPath( getResourcesPath( ASSETS_PATH ), path );
}

fs::path getResourcesImagesAssetsPath( const std::string &path )
{
	return addPath( getResourcesAssetsPath( IMAGE_PATH ), path );
}

fs::path getResourcesJsonAssetsPath( const std::string &path )
{
	return addPath( getResourcesAssetsPath( JSON_PATH ), path );
}

fs::path getResourcesDefaultPath( const string &path )
{
	return addPath( getResourcesPath( DEFAULT_PATH ), path );
}

fs::path getResourcesDefaultSettingsPath( const string &path )
{
	return addPath( getResourcesDefaultPath( SETTINGS_PATH ), path );
}

fs::path getResourcesDefaultShadersPath( const string &path )
{
	return addPath( getResourcesDefaultPath( SHADERS_PATH ), path );
}

fs::path getResourcesWorkingPath( const string &path )
{
	return addPath( getResourcesPath( WORKING_PATH ), path );
}

fs::path getResourcesWorkingSettingsPath( const string &path )
{
	return addPath( getResourcesWorkingPath( SETTINGS_PATH ), path );
}

fs::path getResourcesWorkingShadersPath( const string &path )
{
	return addPath( getResourcesWorkingPath( SHADERS_PATH ), path );
}

fs::path getAppSupportPath( const string &path )
{
	return addPath( ci::app::Platform::get()->getHomeDirectory().remove_trailing_separator(), path );
}

fs::path getAppSupportAssetsPath( const string &path )
{
	return addPath( getAppSupportPath( ASSETS_PATH ), path );
}

fs::path getAppSupportImageAssetsPath( const string &path )
{
	return addPath( getAppSupportAssetsPath( IMAGE_PATH ), path );
}

fs::path getAppSupportJsonAssetsPath( const string &path )
{
	return addPath( getAppSupportAssetsPath( JSON_PATH ), path );
}

fs::path getAppSupportDefaultSessionPath( const string &path )
{
	return addPath( getAppSupportPath( DEFAULT_PATH ), path );
}

fs::path getAppSupportDefaultSessionSettingsPath( const string &path )
{
	return addPath( getAppSupportDefaultSessionPath( SETTINGS_PATH ), path );
}

fs::path getAppSupportDefaultSessionShadersPath( const string &path )
{
	return addPath( getAppSupportDefaultSessionPath( SHADERS_PATH ), path );
}

fs::path getAppSupportWorkingSessionPath( const string &path )
{
	return addPath( getAppSupportPath( WORKING_PATH ), path );
}

fs::path getAppSupportWorkingSessionSettingsPath( const string &path )
{
	return addPath( getAppSupportWorkingSessionPath( SETTINGS_PATH ), path );
}

fs::path getAppSupportWorkingSessionShadersPath( const string &path )
{
	return addPath( getAppSupportWorkingSessionPath( SHADERS_PATH ), path );
}

} // namespace paths
} // namespace reza