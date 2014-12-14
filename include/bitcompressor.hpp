#ifndef BITCOMPRESSOR_HPP
#define BITCOMPRESSOR_HPP

#include <iostream>
#include <vector>

#include "../include/bit7zlibrary.hpp"
#include "../include/bitformat.hpp"
#include "../include/bitguids.hpp"

#include "../include/fsitem.hpp"

using namespace std;
using namespace Bit7z::FileSystem;

namespace Bit7z {
    class BitCompressor {
        public:
            BitCompressor( const Bit7zLibrary& lib, BitOutFormat format );

            void setPassword( const wstring& password, bool crypt_headers = false );
            void setCompressionLevel();
            void enableSolidMode();

            void compress( const vector<wstring>& in_files, const wstring& out_archive ) const;
            void compressFile( const wstring& in_file, const wstring& out_archive ) const;
            void compressFiles( const vector<wstring>& in_files, const wstring& out_archive ) const;
            void compressFiles( const wstring& in_dir, const wstring& filter,
                                const wstring& out_archive, bool search_subdirs = true ) const;
            void compressDirectory( const wstring& in_dir, const wstring& out_archive,
                                    bool search_subdirs = true ) const;

        private:
            const Bit7zLibrary& mLibrary;
            const BitOutFormat mFormat;
            wstring mPassword;
            bool mCryptHeaders;
            bool mSolidMode;

            void compressFS( const vector<FSItem>& in_items, const wstring& out_archive ) const;
    };
}

#endif // BITCOMPRESSOR_HPP