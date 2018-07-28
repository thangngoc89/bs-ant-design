open Antd_Helpers;

[@bs.module] external spin : ReasonReact.reactClass = "antd/lib/spin";

[%bs.raw {|require("antd/lib/spin/style")|}];

[@bs.deriving jsConverter]
type size = [ | `default | `small | `large];

[@bs.obj]
external makeProps :
  (
    ~size: string=?,
    ~spinning: bool=?,
    ~tip: string=?,
    ~delay: int=?,
    ~wrapperClassName: string=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~size=?,
      ~spinning=?,
      ~tip=?,
      ~delay=?,
      ~wrapperClassName=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=spin,
    ~props=
      makeProps(
        ~size=?Js.Option.map((. b) => sizeToJs(b), size),
        ~spinning=?Js.Option.map((. b) => from_bool(b), spinning),
        ~tip?,
        ~delay?,
        ~wrapperClassName?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );