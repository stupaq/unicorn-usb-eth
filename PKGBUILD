# Maintainer: Mateusz Machalica <mateuszmachalica@gmail.com>

pkgname=unicorn-usb-eth-git
pkgver=20120207
pkgrel=1
pkgdesc="Unicorn USB ADSL modem driver."
arch=('i686')
url="https://github.com/stupaq/unicorn-usb-eth"
license=('GPL')
groups=()
depends=()
makedepends=('git')
provides=()
conflicts=()
replaces=()
backup=()
options=()
install=
source=()
noextract=()
md5sums=()

_gitroot="git://github.com/stupaq/unicorn-usb-eth.git"
_gitname="unicorn-usb-eth"

build() {
  cd "$srcdir"
  msg "Connecting to GIT server...."

  if [[ -d "$_gitname" ]]; then
    cd "$_gitname" && git pull origin
    msg "The local files are updated."
  else
    git clone "$_gitroot" "$_gitname"
  fi

  msg "GIT checkout done or server timeout"
  msg "Starting build..."

  rm -rf "$srcdir/$_gitname-build"
  git clone "$srcdir/$_gitname" "$srcdir/$_gitname-build"
  cd "$srcdir/$_gitname-build"

  # build
  make
}

package() {
  cd "$srcdir/$_gitname-build"

  # install
  make DESTDIR="$pkgdir/" install
}

# vim:set ts=2 sw=2 et:
