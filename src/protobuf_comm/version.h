
/***************************************************************************
 *  version.h - protobuf version information
 *
 *  Created: Fri Aug 07 23:29:09 2009
 *  Copyright  2006-2016  Tim Niemueller [www.niemueller.de]
 *
 ****************************************************************************/

/*  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version. A runtime exception applies to
 *  this software (see LICENSE.GPL_WRE file mentioned below for details).
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  Read the full text in the LICENSE.GPL_WRE file in the doc directory.
 */

#ifndef __CORE_VERSION_H_
#define __CORE_VERSION_H_

#define PROTOBUF_COMM_VERSION_MAJOR  0
#define PROTOBUF_COMM_VERSION_MINOR  6
#define PROTOBUF_COMM_VERSION_MICRO  0

#define PROTOBUF_COMM_VERSION_GT(major, minor) ((PROTOBUF_COMM_MAJOR_VERSION  > major) || (PROTOBUF_COMM_MAJOR_VERSION == major) && (PROTOBUF_COMM_MINOR_VERSION  > minor))
#define PROTOBUF_COMM_VERSION_GE(major, minor) ((PROTOBUF_COMM_MAJOR_VERSION  > major) || (PROTOBUF_COMM_MAJOR_VERSION == major) && (PROTOBUF_COMM_MINOR_VERSION >= minor))
#define PROTOBUF_COMM_VERSION_EQ(major, minor) ((PROTOBUF_COMM_MAJOR_VERSION == major) && (PROTOBUF_COMM_MINOR_VERSION == minor))
#define PROTOBUF_COMM_VERSION_NE(major, minor) ((PROTOBUF_COMM_MAJOR_VERSION != major) || (PROTOBUF_COMM_MINOR_VERSION != minor))
#define PROTOBUF_COMM_VERSION_LE(major, minor) ((PROTOBUF_COMM_MAJOR_VERSION  < major) || (PROTOBUF_COMM_MAJOR_VERSION == major) && (PROTOBUF_COMM_MINOR_VERSION <= minor))
#define PROTOBUF_COMM_VERSION_LT(major, minor) ((PROTOBUF_COMM_MAJOR_VERSION  < major) || (PROTOBUF_COMM_MAJOR_VERSION == major) && (PROTOBUF_COMM_MINOR_VERSION  < minor))

#define PROTOBUF_COMM_VERSION_GT_MICRO(major, minor, micro)			\
  ((PROTOBUF_COMM_MAJOR_VERSION  > major) ||					\
   (PROTOBUF_COMM_MAJOR_VERSION == major) && (PROTOBUF_COMM_MINOR_VERSION  > minor) || \
   (PROTOBUF_COMM_MAJOR_VERSION == major) && (PROTOBUF_COMM_MINOR_VERSION == minor) && (PROTOBUF_COMM_MICRO_VERSION > minor))

#define PROTOBUF_COMM_VERSION_xstr(s) PROTOBUF_COMM_VERSION_str(s)
#define PROTOBUF_COMM_VERSION_str(s) #s

#define PROTOBUF_COMM_VERSION_STRING \
  PROTOBUF_COMM_VERSION_xstr(PROTOBUF_COMM_VERSION_MAJOR) "."	 \
  PROTOBUF_COMM_VERSION_xstr(PROTOBUF_COMM_VERSION_MINOR) "."  \
  PROTOBUF_COMM_VERSION_xstr(PROTOBUF_COMM_VERSION_MICRO)

#endif
