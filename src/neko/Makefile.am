bin_SCRIPTS=neko

neko: neko.in
	cp neko.in neko
	sed -i "s/MAINVER/$(VERSION)/g" neko
	chmod +x neko

clean:
	rm -rf neko
