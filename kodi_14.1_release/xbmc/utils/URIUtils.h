/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "StdString.h"

class CURL;

class URIUtils
{
public:
  URIUtils(void);
  virtual ~URIUtils(void);
  static bool IsInPath(const CStdString &uri, const CStdString &baseURI);

  static CStdString GetDirectory(const CStdString &strFilePath);

  static const CStdString GetFileName(const CURL& url);
  static const CStdString GetFileName(const CStdString& strFileNameAndPath);

  static std::string GetExtension(const CURL& url);
  static std::string GetExtension(const std::string& strFileName);

  /*!
   \brief Check if there is a file extension
   \param strFileName Path or URL to check
   \return \e true if strFileName have an extension.
   \note Returns false when strFileName is empty.
   \sa GetExtension
   */
  static bool HasExtension(const CStdString& strFileName);

  /*!
   \brief Check if filename have any of the listed extensions
   \param strFileName Path or URL to check
   \param strExtensions List of '.' prefixed lowercase extensions seperated with '|'
   \return \e true if strFileName have any one of the extensions.
   \note The check is case insensitive for strFileName, but requires
         strExtensions to be lowercase. Returns false when strFileName or
         strExtensions is empty.
   \sa GetExtension
   */
  static bool HasExtension(const CStdString& strFileName, const CStdString& strExtensions);
  static bool HasExtension(const CURL& url, const CStdString& strExtensions);

  static void RemoveExtension(std::string& strFileName);
  static CStdString ReplaceExtension(const CStdString& strFile,
                                     const CStdString& strNewExtension);
  static void Split(const std::string& strFileNameAndPath, 
                    std::string& strPath, std::string& strFileName);
  static std::vector<std::string> SplitPath(const CStdString& strPath);

  static void GetCommonPath(std::string& strPath, const std::string& strPath2);
  static std::string GetParentPath(const std::string& strPath);
  static bool GetParentPath(const std::string& strPath, std::string& strParent);

  /* \brief Change the base path of a URL: fromPath/fromFile -> toPath/toFile
    Handles changes in path separator and filename URL encoding if necessary to derive toFile.
    \param fromPath the base path of the original URL
    \param fromFile the filename portion of the original URL
    \param toPath the base path of the resulting URL
    \return the full path.
   */
  static std::string ChangeBasePath(const std::string &fromPath, const std::string &fromFile, const std::string &toPath);

  static CURL SubstitutePath(const CURL& url, bool reverse = false);
  static CStdString SubstitutePath(const CStdString& strPath, bool reverse = false);

  /*! \brief Check whether a URL is a given URL scheme.
   Comparison is case-insensitve as per RFC1738
   \param url a std::string path.
   \param type a lower-case scheme name, e.g. "smb".
   \return true if the url is of the given scheme, false otherwise.
   \sa PathStarts, PathEquals
   */
  static bool IsProtocol(const std::string& url, const std::string& type);

  /*! \brief Check whether a path starts with a given start.
   Comparison is case-sensitive.
   Use IsProtocol() to compare the protocol portion only.
   \param path a std::string path.
   \param start the string the start of the path should be compared against.
   \return true if the path starts with the given string, false otherwise.
   \sa IsProtocol, PathEquals
   */
  static bool PathStarts(const std::string& path, const char *start);

  /*! \brief Check whether a path equals another path.
   Comparison is case-sensitive.
   \param path1 a std::string path.
   \param path2 the second path the path should be compared against.
   \param ignoreTrailingSlash ignore any trailing slashes in both paths
   \return true if the paths are equal, false otherwise.
   \sa IsProtocol, PathStarts
   */
  static bool PathEquals(const std::string& path1, const std::string &path2, bool ignoreTrailingSlash = false);

  static bool IsAddonsPath(const CStdString& strFile);
  static bool IsSourcesPath(const CStdString& strFile);
  static bool IsCDDA(const CStdString& strFile);
  static bool IsDAAP(const CStdString& strFile);
  static bool IsDAV(const CStdString& strFile);
  static bool IsDOSPath(const CStdString &path);
  static bool IsDVD(const CStdString& strFile);
  static bool IsFTP(const CStdString& strFile);
  static bool IsUDP(const CStdString& strFile);
  static bool IsTCP(const CStdString& strFile);
  static bool IsHD(const CStdString& strFileName);
  static bool IsHDHomeRun(const CStdString& strFile);
  static bool IsSlingbox(const CStdString& strFile);
  static bool IsHTSP(const CStdString& strFile);
  static bool IsInArchive(const CStdString& strFile);
  static bool IsInRAR(const CStdString& strFile);
  static bool IsInternetStream(const std::string& path, bool bStrictCheck = false);
  static bool IsInternetStream(const CURL& url, bool bStrictCheck = false);
  static bool IsInAPK(const CStdString& strFile);
  static bool IsInZIP(const CStdString& strFile);
  static bool IsISO9660(const CStdString& strFile);
  static bool IsLiveTV(const CStdString& strFile);
  static bool IsPVRRecording(const CStdString& strFile);
  static bool IsMultiPath(const CStdString& strPath);
  static bool IsMusicDb(const CStdString& strFile);
  static bool IsMythTV(const CStdString& strFile);
  static bool IsNfs(const CStdString& strFile);  
  static bool IsAfp(const CStdString& strFile);    
  static bool IsOnDVD(const CStdString& strFile);
  static bool IsOnLAN(const CStdString& strFile);
  static bool IsHostOnLAN(const CStdString& hostName, bool offLineCheck = false);
  static bool IsPlugin(const CStdString& strFile);
  static bool IsScript(const CStdString& strFile);
  static bool IsRAR(const CStdString& strFile);
  static bool IsRemote(const CStdString& strFile);
  static bool IsSmb(const CStdString& strFile);
  static bool IsSpecial(const CStdString& strFile);
  static bool IsStack(const CStdString& strFile);
  static bool IsTuxBox(const CStdString& strFile);
  static bool IsUPnP(const CStdString& strFile);
  static bool IsURL(const CStdString& strFile);
  static bool IsVideoDb(const CStdString& strFile);
  static bool IsVTP(const CStdString& strFile);
  static bool IsAPK(const CStdString& strFile);
  static bool IsZIP(const CStdString& strFile);
  static bool IsArchive(const CStdString& strFile);
  static bool IsBluray(const CStdString& strFile);
  static bool IsAndroidApp(const CStdString& strFile);
  static bool IsLibraryFolder(const CStdString& strFile);
  static bool IsLibraryContent(const std::string& strFile);
  static bool IsPVRChannel(const CStdString& strFile);
  static bool IsUsingFastSwitch(const CStdString& strFile);

  static void AddSlashAtEnd(std::string& strFolder);
  static bool HasSlashAtEnd(const std::string& strFile, bool checkURL = false);
  static void RemoveSlashAtEnd(std::string& strFolder);
  static bool CompareWithoutSlashAtEnd(const CStdString& strPath1, const CStdString& strPath2);
  static std::string FixSlashesAndDups(const std::string& path, const char slashCharacter = '/', const size_t startFrom = 0);
  /**
   * Convert path to form without duplicated slashes and without relative directories
   * Strip duplicated slashes
   * Resolve and remove relative directories ("/../" and "/./")
   * Will ignore slashes with other direction than specified
   * Will not resolve path starting from relative directory
   * @warning Don't use with "protocol://path"-style URLs
   * @param path string to process
   * @param slashCharacter character to use as directory delimiter
   * @return transformed path
   */
  static std::string CanonicalizePath(const std::string& path, const char slashCharacter = '\\');

  static CURL CreateArchivePath(const std::string& type,
                                const CURL& archiveUrl,
                                const std::string& pathInArchive = "",
                                const std::string& password = "");

  static CStdString AddFileToFolder(const CStdString &strFolder, const CStdString &strFile);

  static bool HasParentInHostname(const CURL& url);
  static bool HasEncodedHostname(const CURL& url);
  static bool HasEncodedFilename(const CURL& url);

  /*!
   \brief Cleans up the given path by resolving "." and ".."
   and returns it.

   This methods goes through the given path and removes any "."
   (as it states "this directory") and resolves any ".." by
   removing the previous directory from the path. This is done
   for file paths and host names (in case of VFS paths).

   \param path Path to be cleaned up
   \return Actual path without any "." or ".."
   */
  static std::string GetRealPath(const std::string &path);

  /*!
   \brief Updates the URL encoded hostname of the given path

   This method must only be used to update paths encoded with
   the old (Eden) URL encoding implementation to the new (Frodo)
   URL encoding implementation (which does not URL encode -_.!().

   \param strFilename Path to update
   \return True if the path has been updated/changed otherwise false
   */
  static bool UpdateUrlEncoding(std::string &strFilename);

private:
  static std::string resolvePath(const std::string &path);
};

