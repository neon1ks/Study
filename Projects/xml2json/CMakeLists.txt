cmake_minimum_required(VERSION 3.5)

project(xml2json LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

set(XML2JSON_HEADERS
    xml2json.hpp
    rapidjson/allocators.h
    rapidjson/document.h
    rapidjson/encodedstream.h
    rapidjson/encodings.h
    rapidjson/error/en.h
    rapidjson/error/error.h
    rapidjson/filereadstream.h
    rapidjson/filewritestream.h
    rapidjson/fwd.h
    rapidjson/internal/biginteger.h
    rapidjson/internal/dtoa.h
    rapidjson/internal/itoa.h
    rapidjson/internal/pow10.h
    rapidjson/internal/stack.h
    rapidjson/internal/strtod.h
    rapidjson/internal/diyfp.h
    rapidjson/internal/ieee754.h
    rapidjson/internal/meta.h
    rapidjson/internal/regex.h
    rapidjson/internal/strfunc.h
    rapidjson/internal/swap.h
    rapidjson/istreamwrapper.h
    rapidjson/memorybuffer.h
    rapidjson/memorystream.h
    rapidjson/msinttypes/inttypes.h
    rapidjson/msinttypes/stdint.h
    rapidjson/ostreamwrapper.h
    rapidjson/pointer.h
    rapidjson/prettywriter.h
    rapidjson/rapidjson.h
    rapidjson/reader.h
    rapidjson/schema.h
    rapidjson/stream.h
    rapidjson/stringbuffer.h
    rapidjson/writer.h
    rapidxml/rapidxml.hpp
    rapidxml/rapidxml_iterators.hpp
    rapidxml/rapidxml_print.hpp
    rapidxml/rapidxml_utils.hpp
    rapidjson/allocators.h
    rapidjson/document.h
    rapidjson/encodedstream.h
    rapidjson/encodings.h
    rapidjson/error/en.h
    rapidjson/error/error.h
    rapidjson/filereadstream.h
    rapidjson/filewritestream.h
    rapidjson/fwd.h
    rapidjson/internal/biginteger.h
    rapidjson/internal/dtoa.h
    rapidjson/internal/itoa.h
    rapidjson/internal/pow10.h
    rapidjson/internal/stack.h
    rapidjson/internal/strtod.h
    rapidjson/internal/diyfp.h
    rapidjson/internal/ieee754.h
    rapidjson/internal/meta.h
    rapidjson/internal/regex.h
    rapidjson/internal/strfunc.h
    rapidjson/internal/swap.h
    rapidjson/istreamwrapper.h
    rapidjson/memorybuffer.h
    rapidjson/memorystream.h
    rapidjson/msinttypes/inttypes.h
    rapidjson/msinttypes/stdint.h
    rapidjson/ostreamwrapper.h
    rapidjson/pointer.h
    rapidjson/prettywriter.h
    rapidjson/rapidjson.h
    rapidjson/reader.h
    rapidjson/schema.h
    rapidjson/stream.h
    rapidjson/stringbuffer.h
    rapidjson/writer.h
    rapidxml/rapidxml.hpp
    rapidxml/rapidxml_iterators.hpp
    rapidxml/rapidxml_print.hpp
    rapidxml/rapidxml_utils.hpp
)

set(PROJECT_SOURCES
        main.cpp
        ${XML2JSON_HEADERS}
)

add_executable(xml2json ${PROJECT_SOURCES})

target_link_libraries(xml2json PRIVATE Threads::Threads)
