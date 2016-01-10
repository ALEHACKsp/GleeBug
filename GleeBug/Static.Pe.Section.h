#ifndef STATIC_PE_SECTION_H
#define STATIC_PE_SECTION_H

#include "Static.Region.h"

namespace GleeBug
{
    class Section
    {
    public:
        explicit Section(uint16 index, Region<IMAGE_SECTION_HEADER> & headers, Region<uint8> beforeData, Region<uint8> data)
            : mIndex(index),
            mHeaders(headers),
            mBeforeData(beforeData),
            mData(data)
        {
        }

        uint16 GetIndex() const { return mIndex; }
        IMAGE_SECTION_HEADER & GetHeader() { return mHeaders[mIndex]; }
        const IMAGE_SECTION_HEADER & GetHeader() const { return mHeaders[mIndex]; }
        const Region<uint8> & GetBeforeData() const { return mBeforeData; }
        const Region<uint8> & GetData() const { return mData; }

    private:
        uint16 mIndex;
        Region<IMAGE_SECTION_HEADER> mHeaders;
        Region<uint8> mBeforeData;
        Region<uint8> mData;
    };
};

#endif //STATIC_PE_SECTION_H