[@bs.module "antd/lib/form"] external form: ReasonReact.reactClass = "default";
[@bs.module "antd/lib/form"] [@bs.scope "default"]
external item: ReasonReact.reactClass = "Item";

[%bs.raw {|require("antd/lib/form/style")|}];

[@bs.obj]
external makeProps:
  (
    ~onSubmit: ReactEvent.Form.t => unit=?,
    ~hideRequiredMark: bool=?,
    ~id: string=?,
    ~className: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~colon: bool=?,
    ~validateStatus: string=?,
    ~extra: string=?,
    ~required: bool=?,
    ~label: string=?,
    ~help: string=?,
    ~hasFeedback: bool=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~onSubmit=?,
      ~hideRequiredMark=?,
      ~id=?,
      ~className=?,
      ~style=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=form,
    ~props=
      makeProps(
        ~onSubmit?,
        ~hideRequiredMark?,
        ~id?,
        ~className?,
        ~style?,
        (),
      ),
    children,
  );

module Item = {
  let make =
      (
        ~colon=?,
        ~validateStatus=?,
        ~extra=?,
        ~className=?,
        ~required=?,
        ~style=?,
        ~label=?,
        ~id=?,
        ~help=?,
        ~hasFeedback=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=item,
      ~props=
        makeProps(
          ~colon?,
          ~validateStatus?,
          ~extra?,
          ~className?,
          ~required?,
          ~style?,
          ~label?,
          ~id?,
          ~help?,
          ~hasFeedback?,
          (),
        ),
      children,
    );
};