# THE FILE LISTS IN THIS FILE ARE AUTOMATICALLY GENERATED BY
# tools/cog_files.py, WHICH IS CALLED AUTOMATICALLY WHEN
# RELOADING CMAKE. DO NOT MANUALLY EDIT THE FILE LISTS.

set(belphegor_headers
        #[=[ [[[cog
        import cog, os
        for root, _, files in os.walk("include", topdown=False):
            for f in files:
                if not any(f.endswith(e) for e in [".h", ".hpp"]): continue
                cog.outl(os.path.join(root, f).replace('\\', '/'))
        ]]] ]=]
        include/belphegor/log.hpp
        #[=[ [[[end]]] ]=])

set(belphegor_sources
        #[=[ [[[cog
        import cog, os
        for root, _, files in os.walk("src", topdown=False):
            for f in files:
                if not any(f.endswith(e) for e in [".cpp"]): continue
                cog.outl(os.path.join(root, f).replace('\\', '/'))
        ]]] ]=]
        src/belphegor/log.cpp
        #[=[ [[[end]]] ]=])

set(belphegor_modules
        #[=[ [[[cog
        import cog, os
        for root, _, files in os.walk("src", topdown=False):
            for f in files:
                if not any(f.endswith(e) for e in [".cppm"]): continue
                cog.outl(os.path.join(root, f).replace('\\', '/'))
        ]]] ]=]
        src/belphegor/engine.cppm
        #[=[ [[[end]]] ]=])