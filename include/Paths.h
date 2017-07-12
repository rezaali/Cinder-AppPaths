/*
Copyright(c) 2017 Reza Ali syed.reza.ali@gmail.com www.syedrezaali.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <string>

#include "cinder/Filesystem.h"

namespace reza {
namespace paths {
bool createDirectory( const ci::fs::path &path );
bool createDirectories( const ci::fs::path &path );

void copyDirectory( const ci::fs::path &fromPath, const ci::fs::path &toPath );

ci::fs::path addPath( const ci::fs::path &prefix, const std::string &path, const std::string &seperator = "" );

ci::fs::path getResourcesPath( const std::string &path = "" );
ci::fs::path getResourcesAssetsPath( const std::string &path = "" );
ci::fs::path getResourcesImagesAssetsPath( const std::string &path = "" );
ci::fs::path getResourcesJsonAssetsPath( const std::string &path = "" );

ci::fs::path getResourcesDefaultPath( const std::string &path = "" );
ci::fs::path getResourcesDefaultSettingsPath( const std::string &path = "" );
ci::fs::path getResourcesDefaultShadersPath( const std::string &path = "" );

ci::fs::path getResourcesWorkingPath( const std::string &path = "" );
ci::fs::path getResourcesWorkingSettingsPath( const std::string &path = "" );
ci::fs::path getResourcesWorkingShadersPath( const std::string &path = "" );

ci::fs::path getAppSupportPath( const std::string &path = "" );
ci::fs::path getAppSupportAssetsPath( const std::string &path = "" );
ci::fs::path getAppSupportImageAssetsPath( const std::string &path = "" );
ci::fs::path getAppSupportJsonAssetsPath( const std::string &path = "" );

ci::fs::path getAppSupportDefaultSessionPath( const std::string &path = "" );
ci::fs::path getAppSupportDefaultSessionSettingsPath( const std::string &path = "" );
ci::fs::path getAppSupportDefaultSessionShadersPath( const std::string &path = "" );

ci::fs::path getAppSupportWorkingSessionPath( const std::string &path = "" );
ci::fs::path getAppSupportWorkingSessionSettingsPath( const std::string &path = "" );
ci::fs::path getAppSupportWorkingSessionShadersPath( const std::string &path = "" );

} // namespace paths
} // namespace reza
