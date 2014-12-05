#ifndef FSITEM_HPP
#define FSITEM_HPP

#include <iostream>

#include "7zip/Archive/IArchive.h"
#include "Windows/COM.h"

using namespace std;

namespace Bit7z {
    namespace FileSystem {
        typedef WIN32_FIND_DATA FSItemInfo;

        class FSItem {
            public:
                FSItem( const wstring& path , const wstring& relative_dir = L"" );
                FSItem( const wstring& dir, const wstring& relative_dir, FSItemInfo data );

                bool exists() const;
                bool isDir() const;
                UInt64 size() const;
                FILETIME creationTime() const;
                FILETIME lastAccessTime() const;
                FILETIME lastWriteTime() const;
                wstring name() const;
                wstring relativePath() const;
                wstring fullPath() const;
                UInt32 attributes() const;

            private:
                wstring mDirectory;
                wstring mRelativeDirectory;
                FSItemInfo mFileData;
        };
    }
}

#endif // FSITEM_HPP
