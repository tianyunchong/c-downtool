#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/common.o \
	${OBJECTDIR}/gumbo/gumbo_class_link.o \
	${OBJECTDIR}/gumbo/gumbo_common.o \
	${OBJECTDIR}/links/getlinks.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/test/test.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/local/include -L/usr/include -L/usr/include/curl `pkg-config --cflags --libs gumbo` -l curl  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c-downtool

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c-downtool: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c-downtool ${OBJECTFILES} ${LDLIBSOPTIONS} -s

${OBJECTDIR}/common.o: common.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -s -Icurl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/common.o common.c

${OBJECTDIR}/gumbo/gumbo_class_link.o: gumbo/gumbo_class_link.c
	${MKDIR} -p ${OBJECTDIR}/gumbo
	${RM} "$@.d"
	$(COMPILE.c) -g -s -Icurl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gumbo/gumbo_class_link.o gumbo/gumbo_class_link.c

${OBJECTDIR}/gumbo/gumbo_common.o: gumbo/gumbo_common.c
	${MKDIR} -p ${OBJECTDIR}/gumbo
	${RM} "$@.d"
	$(COMPILE.c) -g -s -Icurl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gumbo/gumbo_common.o gumbo/gumbo_common.c

${OBJECTDIR}/links/getlinks.o: links/getlinks.c
	${MKDIR} -p ${OBJECTDIR}/links
	${RM} "$@.d"
	$(COMPILE.c) -g -s -Icurl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/links/getlinks.o links/getlinks.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -s -Icurl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/test/test.o: test/test.c
	${MKDIR} -p ${OBJECTDIR}/test
	${RM} "$@.d"
	$(COMPILE.c) -g -s -Icurl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/test/test.o test/test.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
