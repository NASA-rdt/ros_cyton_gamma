# Make sure we can find the Actin distribution
get_filename_component(sriptDir ${CMAKE_CURRENT_LIST_FILE} PATH)

#set(toolkits ${sriptDir}/../../../toolkits)

#set(toolkits "/home/lentin/Desktop/Robai/Cyton/toolkits")


set(toolkits $ENV{EC_TOOLKITS})

set(src ${toolkits}/examples/src)
set(external ${toolkits}/../external)
set(render_inc ${external}/render_OSS-20130221-gcc4.6-amd64/OSG-3.1.1/include ${external}/render_OSS-20130221-gcc4.6-amd64/Qt-4.8.3/include)
set(render_lib  ${external}/sensor_OSS-20130213-gcc4.6-amd64/OpenCV-2.4.2/lib ${external}/render_OSS-20130221-gcc4.6-amd64/OSG-3.1.1/lib ${external}/render_OSS-20130221-gcc4.6-amd64/Qt-4.8.3/lib ${external}/sensor_OSS-20130213-gcc4.6-amd64/tiff-3.9.5/lib ${external}/sensor_OSS-20130213-gcc4.6-amd64/libdc1394-2.1.0/lib ${external}/sensor_OSS-20130213-gcc4.6-amd64/libraw1394-2.0.2/lib)



# Set directory to include headers
include_directories(${toolkits}/../include ${external}/boost-20130409-gcc4.6-amd64/boost_1_53_0/include)

# Set directory to library files.
link_directories(${toolkits}/../lib)


set(qt_lib QtCore QtGui)
set(osg_lib osg)

add_definitions(-DEC_BUILD_SHARED_LIBS)
add_definitions(-DEC_HAVE_ACTIN)
add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)



set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(qt_lib QtCore QtGui)
set(osg_lib osg)

link_directories(${external}/boost-20130409-gcc4.6-amd64/boost_1_53_0/lib)
