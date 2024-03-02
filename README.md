# Syati-Examples
An example repository for usage of Syati.

# What is supplied
- **loader**: The source code for the CustomCode loader and crash debugger patches. The loader automatically adjusts the game's memory heaps to fit a large batch of new code. The CustomCode binary that it loads depends on the version of the game played. If a CustomCode binary doesn't exist, the loader initialization is aborted, however, the crash debugger will still be enabled.
- **init.cpp**: Calls all linked static initializers. This is necessary to initialize static variables and constants in the BSS segment of your code. Custom Nerve instances will be stored there, for example.
- **ExtNameObjFactory.cpp**: Extends the existing ``NameObjFactory`` by taking into account your table of new objects. The custom creation table with actor entries is defined in the respective header file.
- **ExtSceneChangeArea.cpp**: A reimplementation of ``SceneChangeArea``'s "control" method. It takes two arguments in, *Obj_arg0* accesses a list to which Galaxy to go to, and *Obj_arg1* determines the white screen fade time.
- **GstRecord.cpp**: Helper code for recording GST object playback files. Requires the external tool [galaxygst](https://github.com/SunakazeKun/galaxygst) to produce GST files during gameplay.
- **PadRecord.cpp**: Helper code for recording PAD input playback files. Requires the external tool [galaxypad](https://github.com/SunakazeKun/galaxypad) to produce PAD files during gameplay.
- **archive.cpp**: A simplified archive loader. It can be used to mount any archive from the game's filesystem and access its stored files. The files are stored in ``StationedHeapNapa``.