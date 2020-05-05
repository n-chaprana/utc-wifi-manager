Name:		utc-wifi-manager
Summary:	Wi-Fi manager utc test utility
Version:	0.0.1
Release:	0
Group:		Network/Testing
License:	Apache-2.0
Source0:	%{name}-%{version}.tar.gz
BuildRequires:	cmake
BuildRequires:	pkgconfig(capi-base-common)
BuildRequires:	pkgconfig(capi-network-wifi-manager)
BuildRequires:	pkgconfig(capi-system-info)
BuildRequires:	pkgconfig(glib-2.0)
BuildRequires:	pkgconfig(gio-2.0)
BuildRequires:	pkgconfig(dlog)

%description
Wi-Fi manager utc test utility to run on target.

%prep
%setup -q

%build
cmake .
make %{?_smp_mflags}

%install
%make_install
mkdir -p %{buildroot}/opt/usr/data/network
cp %{name}.conf %{buildroot}/opt/usr/data/network

%post

%postun

%files
%manifest %{name}.manifest
%license LICENSE
%config /opt/usr/data/network/%{name}.conf
%{_bindir}/%{name}
