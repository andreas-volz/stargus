
LuaTest_sources = files(
  'CreateUnitLuaTest.cpp',
  'LuaTest.cpp'
  )

executable('LuaTest',
			LuaTest_sources,
			include_directories : [config_incdir],
			dependencies : [log4cxx_dep, libsauwetter_dep, libstartool_dep],
			install : false)


