```yaml
name: CI
# Workflow file for windows
# https://www.blurredcode.com/2021/05/4756a873/
on:
  push:
    branches: [ master ]
  pull_request:
    branches: [ master ]
jobs:
  job:
    name: ${{ matrix.os }}-build
    runs-on: ${{ matrix.os }}
    strategy:
      fail-fast: false
      matrix:
        os: [ windows-latest,ubuntu-latest ]
        include:
          - os: windows-latest
            triplet: x64-windows
          - os: windows-latest
            triplet: x64-linux
    env:
      VCPKG_ROOT: '${{ github.workspace }}/vcpkg'
    steps:
      - name: Checkout
        uses: actions/checkout@v2
        with:
          submodules: recursive

      - name: Get cmake
        # Install latest CMake.
        uses: lukka/get-cmake@latest

      - name: Restore vcpkg and its artifacts.
        uses: actions/cache@v2
        id: vcpkg-cache
        with:
          # The first path is where vcpkg generates artifacts while consuming the vcpkg.json manifest file.
          # The second path is the location of vcpkg (it contains the vcpkg executable and data files).
          # The other paths starting with '!' are exclusions: they contain termporary files generated during the build of the installed packages.
          path: |
            ${{ env.VCPKG_ROOT }}
            ${{ github.workspace }}/build/vcpkg_installed
            !${{ env.VCPKG_ROOT }}/.git
            !${{ env.VCPKG_ROOT }}/buildtrees
            !${{ env.VCPKG_ROOT }}/packages
            !${{ env.VCPKG_ROOT }}/downloads
          # The key is composed in a way that it gets properly invalidated: this must happen whenever vcpkg's Git commit id changes, or the list of packages changes. In this case a cache miss must happen and a new entry with a new key with be pushed to GitHub the cache service.
          # The key includes: hash of the vcpkg.json file, the hash of the vcpkg Git commit id, and the used vcpkg's triplet. The vcpkg's commit id would suffice, but computing an hash out it does not harm.
          # Note: given a key, the cache content is immutable. If a cache entry has been created improperly, in order the recreate the right content the key must be changed as well, and it must be brand new (i.e. not existing already).
          key: |
            ${{ hashFiles( 'vcpkg.json' ) }}-${{ runner.os }}-cache-key-v1

      - name: Get vcpkg(windows)
        if: ${{ runner.os == 'Windows' && steps.vcpkg-cache.outputs.cache-hit != 'true' }}
        run: |
          cd ${{ github.workspace }}
          mkdir build -force
          git clone https://github.com/Microsoft/vcpkg.git
          cd vcpkg
          .\bootstrap-vcpkg.bat
      - name: Get vcpkg(Linux)
        if: ${{ runner.os == 'Linux' && steps.vcpkg-cache.outputs.cache-hit != 'true' }}
        run: |
          cd ${{ github.workspace }}
          mkdir -p build
          git clone https://github.com/Microsoft/vcpkg.git
          cd vcpkg
          ./bootstrap-vcpkg.sh

      - name: install deps and remove vcpkg(Linux)
        if: runner.os == 'Linux'
        run: |
          sudo apt install -y libgl1-mesa-dev libglu1-mesa-dev xorg-dev libxcursor-dev libxrandr-dev libxinerama-dev libxi-dev
          sudo rm -rf "$VCPKG_INSTALLATION_ROOT"
        shell: bash

      - name: remove system vcpkg(windows)
        if: runner.os == 'Windows'
        run: rm -rf "$VCPKG_INSTALLATION_ROOT"
        shell: bash

      - uses: ilammy/msvc-dev-cmd@v1
        if: runner.os == 'Windows'
        with:
          arch: x64

      #      - name: Setup tmate session
      #        uses: mxschmitt/action-tmate@v3
      #        if: runner.os == 'Linux'

      - name: Running cmake
        run: |
          cd ${{ github.workspace }}
          cd build
          cmake .. -DCMAKE_TOOLCHAIN_FILE=${{ github.workspace }}/vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_BUILD_TYPE=Release


      - name: Build Solution
        run: |
          cd build
          cmake --build . --parallel --config Release
```

