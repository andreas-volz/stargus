#!/bin/sh

# print out some help
print_help()
{
cat << EOF
Using:
$0 <UnitTestName>
EOF
exit 1;
}

if [ "$#" = "0" ]; then
        print_help;
fi

NAME=$1
TEMPLATE=Template

TEMPLATE_UPPERCASE=`echo "$TEMPLATE" | tr a-z A-Z`
NAME_UPPERCASE=`echo "$NAME" | tr a-z A-Z`

#echo $UPPERCASE

if ! test -d $NAME; then    
    sed "s/$TEMPLATE/"$NAME"/g" ${TEMPLATE}Test.cpp > ${NAME}Test_.cpp
    sed "s/$TEMPLATE_UPPERCASE/"$NAME_UPPERCASE"/g" ${NAME}Test_.cpp > ${NAME}Test.cpp
    rm ${NAME}Test_.cpp
    
    sed "s/$TEMPLATE/"$NAME"/g" ${TEMPLATE}Test.h  > ${NAME}Test_.h
    sed "s/$TEMPLATE_UPPERCASE/"$NAME_UPPERCASE"/g" ${NAME}Test_.h > ${NAME}Test.h
    rm ${NAME}Test_.h    
    
    echo "Test Class '${NAME}Test.cpp/.h' erfolgreich erzeugt."
fi
