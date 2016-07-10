# scconfig confguratiion

# where to put things
BIN=scconfig

# build flags
USER_CFLAGS=-Wall -g -DGENCALL
USER_LDFLAGS=
USER_OBJS=

# parts selection
SCC_PLUGINS=default c99 scripts parser parsgen math socket sul tmpasm userpass
SCC_CONFIGURE=configure
