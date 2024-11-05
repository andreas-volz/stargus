#!/bin/bash

DAT_FILES="units_dat weapons_dat file_tbl flingy_dat sprites_dat images_dat sfxdata_dat portdata_dat upgrades_dat orders_dat techdata_dat mapdata_dat"
TILESET_FILES="tileset_cv5  tileset_dddata_bin  tileset_vf4  tileset_vr4  tileset_vx4"
CHK_FILES="chk_parser"
KSY_FILES="$DAT_FILES $CHK_FILES $TILESET_FILES"
# run without parameter
if [ $# = 0 ]; then
  echo -e "Run:\n"
  echo -e "kaitai_generate.sh [cpp|doc]\n"
  exit;
fi

if [ "$1" = "cpp" ]; then
	echo "Generate C++ source files..."
	for item in $KSY_FILES
	do
		rm -f $item.cpp $item.h
		KSY=$item.ksy
		kaitai-struct-compiler $KSY -t cpp_stl
	done
elif [ "$1" = "doc" ]; then
	echo "Generate DOT graph files and convert to SVG..."
	## where to store the docs
	mkdir -p ../../doc/kaitai
	for item in $KSY_FILES
	do
		KSY=$item.ksy
		DOT=$item.dot
		SVG=$item.svg
		echo "Generating source and documentation from: $KSY"
		kaitai-struct-compiler $KSY -t graphviz
		dot $DOT -Tsvg > ../../doc/kaitai/$SVG
		mv $DOT ../../doc/kaitai/
	done
fi

