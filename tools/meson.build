json_transition_sources = files('json_transition.cpp')

executable('json_transition', 
	json_transition_sources,
	dependencies : [nlohmann_json_dep, png_dep],
	install : false)

subdir('sauwetter')
subdir('scdat2json')
subdir('grptool')
subdir('iscriptconverter')
subdir('tiled_converter')