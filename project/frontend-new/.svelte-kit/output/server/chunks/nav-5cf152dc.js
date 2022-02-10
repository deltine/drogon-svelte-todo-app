import { c as create_ssr_component, b as add_attribute } from "./index-dbf0e059.js";
var logo = "/_app/assets/svelte-logo-87df40b8.svg";
const Nav = create_ssr_component(($$result, $$props, $$bindings, slots) => {
  return `<nav class="${"flex items-center p-5 w-full bg-slate-700 h-10"}"><img class="${"h-9 w-6"}"${add_attribute("src", logo, 0)} alt="${"SvelteKit"}">

	<div class="${"flex justify-between w-full"}"><div><a class="${"align-middle mx-4 text-lg text-blue-300"}" href="${"/"}">Home</a>
			<a class="${"align-middle mx-4 text-lg text-blue-300"}" href="${"/about"}">About</a></div>
		<div>
			<a class="${"align-middle mx-4 text-lg text-blue-300"}" href="${"javascript:void(0)"}">SignUp</a>
			
			<a class="${"align-middle mx-4 text-lg text-blue-300"}" href="${"javascript:void(0)"}">SignIn</a>
			
			<a class="${"align-middle mx-4 text-lg text-blue-300"}" href="${"javascript:void(0)"}">SignOut</a></div></div></nav>`;
});
export { Nav as N };
