
clean:
	@rm -r asm
	@rm -r assets

split:
	@python3 -m splat split ./doraemon.yaml 