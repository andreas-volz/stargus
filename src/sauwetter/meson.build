sauwetter_sources = files(
	'Hurricane.cpp',
	'Breeze.cpp',
	'Casc.cpp',
	'Storm.cpp',
	'FileUtil.cpp',
	'platform.cpp',
	'DataChunk.cpp',
	'StringUtil.cpp'
)

inc = include_directories('..')

libsauwetter = library('sauwetter',
	sauwetter_sources,
	include_directories : [config_incdir, inc],
	dependencies : [casc_dep, storm_dep, zlib_dep, png_dep, imagemagickpp_dep, log4cxx_dep, bzip2_dep],
	install : true)

libsauwetter_dep = declare_dependency(include_directories : [config_incdir, inc],
  link_with : libsauwetter)